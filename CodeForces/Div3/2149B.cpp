#include <bits/stdc++.h>
using namespace std;

int getResult(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    //Choose consecutive pairs
    int maxi = 0;
    for (int i=0; i<n; i+=2){
        int val = abs(nums[i] - nums[i+1]);
        maxi = max(maxi, val);
    }
    return maxi;
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
        int res = getResult(nums);
        cout << res << endl;
        t--;
    }
}