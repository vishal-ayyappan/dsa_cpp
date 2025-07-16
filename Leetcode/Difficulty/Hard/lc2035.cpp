#include <bits/stdc++.h>
using namespace std;

//Using Two Pointers
//This is wrong, it is just to show that greedy does not work
int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += nums[i];
    }
    sort(nums.begin(), nums.end());
    if ((n/2)%2 == 0){
        //Choose first pair
        int sum1 = 0;
        int count = 0;
        int i = 0;
        int j = n-1;
        while (i < j && count < n/2){
            sum1 += nums[i] + nums[j];
            i++;
            j--;
            count += 2;
        }
        int sum2 = sum - sum1;
        return abs(sum1-sum2);
    }
    int sum1 = 0;
    int count = 0;
    int i = 0;
    int j = n-1;
    while (i < j && count < n/2-1){
        sum1 += nums[i] + nums[j];
        i++;
        j--;
        count += 2;
    }
    int sum2 = sum - sum1 - nums[i] - nums[j];
    //2 Cases
    //1/ 
    int newsum1 = sum1 + nums[i];
    int newsum2 = sum2 + nums[j];
    int mini1 = abs(newsum1-newsum2);
    //2/
    int nsum1 = sum1 + nums[j];
    int nsum2 = sum2 + nums[i];
    int mini2 = abs(nsum1 - nsum2);
    return min(mini1, mini2);
}



//Using "Meet in the Middle" Approach
//Divide the array into 2 equal halves
//Get the subset sums with the the number of elements for each half

void generateSubsetSums(vector<int> num, unordered_map<int, vector<int>>& mpp){
    //Store the subset sum along with the count of how many elements contributed to the sum.
    //Generate all subsets
    int n = num.size();
    int total = 1<<n;
    for (int mask=0; mask<total; mask++){
        int sum = 0;
        int count = 0;
        for (int i=0; i<n; i++){
            if (mask & (1<<i)){
                sum += num[i];
                count++;
            }
        }
        mpp[count].push_back(sum);
    }
}   

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int middle = n/2;
    int total = accumulate(nums.begin(), nums.end(), 0);
    unordered_map<int, vector<int>> leftMap;
    unordered_map<int, vector<int>> rightMap;
    vector<int> left; 
    left.assign(nums.begin(), nums.begin()+middle);
    vector<int> right;
    right.assign(nums.begin()+middle, nums.end());
    generateSubsetSums(left, leftMap);
    generateSubsetSums(right, rightMap);
    for (auto& it : rightMap){
        //All the vectors of each count must be sorted for binary search
        sort(it.second.begin(), it.second.end());
    }
    //Now you exactly need half the size of subset.
    int result = INT_MAX;
    for (int i=0; i<=middle; i++){
        if (leftMap.find(i) == leftMap.end() || rightMap.find(middle-1) == rightMap.end()) continue;
        vector<int> leftVec = leftMap[i];
        vector<int> rightVec = rightMap[middle-i];
        int size = leftVec.size();
        for (int j=0; j<size; j++){
            //The sum of half the subset, should be as close to S/2
            int a = leftVec[j];
            int b = total/2 - a;
            //Check if b is in rightVec (So that's why b should be sorted)
            int idx = lower_bound(rightVec.begin(), rightVec.end(), b) - rightVec.begin();
            if (idx != rightVec.size()){
                int combined = a + rightVec[idx]; //S1
                int diff = abs(total - 2*combined); //|S1-S2| should be minimized
                result = min(result, diff);
            }
            //if it is the maximum value in the vector, lower bound gives the last idx as output.
            else if (idx != 0){
                idx--;
                int combined = a + rightVec[idx]; //S1
                int diff = abs(total - 2*combined); //|S1-S2| should be minimized
                result = min(result, diff);
            }
        }
    }
    return result;
}