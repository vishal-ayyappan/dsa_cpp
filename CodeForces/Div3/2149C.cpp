#include <bits/stdc++.h>
using namespace std;

//TC Worst Case (n*nlogn) Too heavy

// void helper(priority_queue<int, vector<int>, greater<int>>& missing, int mex, priority_queue<pair<int, int>>& pq, int& count){
//     while (missing.top() != mex){
//         //Get the max element from the array
//         auto item = pq.top();
//         pq.pop();
//         int val = item.first;
//         int freq = item.second;
//         while (freq > 0 && missing.top() != mex){
//             int og_mex = missing.top(); missing.pop();
//             pq.push({og_mex, 1});
//             freq--;
//             count++;
//         }
//         //This would be a missing element
//         if (freq == 0) missing.push(val);
//         if (missing.top() == mex) break;
//     }
// }

// //mex smallest non negative integer that is not in the array
// int getMinOperations(vector<int>& nums, int mex){
//     //In one operation, you can change any el to a value in the range [0, n];
//     int n = nums.size();
//     unordered_map<int, int> mpp; 
//     for (int i=0; i<n; i++) mpp[nums[i]]++; //n
//     priority_queue<pair<int, int>> pq; //Max Heap
//     for (auto& it : mpp) pq.push({it.first, it.second}); //plogp
//     //We make sure, we fill the smaller mex's first.
//     //Get all the possible elements that are not in the array
//     priority_queue<int, vector<int>, greater<int>> missing;
//     for (int i=0; i<=n; i++) if (mpp.find(i) == mpp.end()) missing.push(i); //n
//     int count = 0;
//     if (mpp.find(mex) == mpp.end()){
//         //If nothing is missing and you cant find mex, then that mex is the el after the last el.
//         if (missing.empty()) return 0;
//         helper(missing, mex, pq, count);   
//     }
//     //If it is in the map
//     else{
//         while (mpp[mex] != 0 && missing.top() < mex){
//             //Check for smaller elements that are not in the map
//             int og_mex = missing.top(); missing.pop();
//             //Push it in the max heap
//             pq.push({og_mex, 1});
//             mpp[mex]--;
//             count++;
//         }
//         //then mex is the mex of the array
//         if (missing.top() > mex) count += mpp[mex];
//         //if mpp[mex] count is 0 and there is still a smaller element
//         else{
//             missing.push(mex);
//             helper(missing, mex, pq, count);
//         }
//     }
//     return count;
// }


//Optimal 

int getMinOperations(vector<int>& nums, int mex){
    int n = nums.size();
    unordered_map<int, int> mpp; 
    for (int i=0; i<n; i++) mpp[nums[i]]++; 
    int count = 0;
    //Case 1 : If mex is not in array
    if (mpp.find(mex) == mpp.end()){
        //Check if smaller number exists
        for (int i=0; i<mex; i++){
            if (mpp.find(i) == mpp.end()) count++;
        }
    }
    //Case 2 : If mex is in array
    else{
        int freq = mpp[mex];
        int i = 0;
        while(freq != 0 && i < mex){
            //If there is smaller element
            if (mpp.find(i) == mpp.end()){
                count++;
                freq--;
            }
            i++;
        }
        if (freq != 0) count += freq;
        else {
            for (int j=i; j<mex; j++) {
                if (mpp.find(j) == mpp.end()) count++;
            }
        }
    }
    return count;
}

int main(){
    int t; cin >> t;
    while (t > 0){
        int n; cin >> n;
        int mex; cin >> mex;
        vector<int> nums;
        for (int i=0; i<n; i++){
            int val; cin >> val;
            nums.push_back(val);
        }
        int res = getMinOperations(nums, mex);
        cout << res << endl;
        t--;
    }
    return 0;
}