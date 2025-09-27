#include <bits/stdc++.h>
using namespace std;


int getMinOperations(vector<int>& nums){
    int n = nums.size();
    //Store the count of 0's
    int zero_count = 0;
    //Store the count of -ves
    int neg_count = 0;
    //If it contains odd negatives, store the least negative element
    int least_negative = INT_MIN;
    for (int i=0; i<n; i++){
        if (nums[i] == 0) zero_count++;
        else if (nums[i] < 0){
            neg_count++;
            least_negative = max(least_negative, nums[i]);
        }
    }
    int res = 0;
    res += zero_count;
    if (neg_count % 2 == 1) {
        res += 1 - least_negative;
    }
    return res;
}

int main(){
    int t; cin >> t;
    while (t > 0){
        int n; cin >> n;
        vector<int> nums;
        for (int i=0; i<n; i++){
            int val; cin >> val;
            nums.push_back(val);
        }
        int res = getMinOperations(nums);
        cout << res << endl;
        t--;
    }
    return 0;
}