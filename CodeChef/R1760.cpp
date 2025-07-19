#include <bits/stdc++.h>
using namespace std;

//Approach 1 - Using DP
int getMaxRec(vector<int>& nums, int idx, int k, int x, vector<vector<vector<int>>>& dp){
    if (idx == nums.size()-1){
        if (k == 0) return 0;
        if (k == 1) return nums[idx];
        if (k == 2) return nums[idx] + x;
        return INT_MIN;
    }
    if (dp[idx][k][x] != -1) return dp[idx][k][x];
    //Three Ways
    //1. Do nothing
    int oneWay = getMaxRec(nums, idx+1, k, x, dp);
    //2. Pay 1 coin.
    int twoWay = INT_MIN;
    if (k >= 1) twoWay = nums[idx] + getMaxRec(nums, idx+1, k-1, x+1, dp);
    int threeWay = INT_MIN;
    if (k >= 2) threeWay = nums[idx] + x + getMaxRec(nums, idx+1, k-2, x+1, dp);
    dp[idx][k][x] = max({oneWay, twoWay, threeWay});
    return dp[idx][k][x];
}

//dp[idx][k][x] --> max sum that you can get starting at index idx, with 
//k coins left and 'x' operations done so far.
vector<int> helper(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (2*n + 1, vector<int> (n+1, -1)));
    for (int i=1; i<=2*n; i++){
        getMaxRec(nums, 0, i, 0, dp);
        ans.push_back(dp[0][i][0]);
    }
    return ans;
    
}

//Approach 2
vector<int> helper(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    //Sort the array in descending order
    sort(nums.begin(), nums.end(), greater<int>());
    //Get the prefix Sum
    vector<int> prefix (n);
    prefix[0] = nums[0];
    for (int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + nums[i];
    }
    for (int k=1; k<=2*n; k++){
        long long maxi = LONG_MIN;
        //You can atmost pick k/2 elements spending 2 coins
        for (int c2=0; c2<=k/2; c2++){
            //c1 + 2*c2 = k
            int c1 = k - 2*c2;
            if (c1 < 0 || c1 + c2 > n) continue;
            int totalPicked = c1 + c2;
            long long base = prefix[totalPicked-1];
            long long bonus = 1LL*c1*c2 + 1LL*c2*(c2-1)/2;
            maxi = max(maxi, base+bonus);
        }
        ans.push_back(maxi);
    }
    return ans; 
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t>0){
	    int n;
	    cin >> n;
	    vector<int> nums (n);
	    for (int i=0; i<n; i++) cin >> nums[i];
	    vector<int> result = helper(nums);
	    for (int i=0; i<result.size(); i++){
	        cout << result[i] << " ";
	    }
	    cout << endl;
	    t--;
	}
}