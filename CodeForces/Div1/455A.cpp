#include <bits/stdc++.h>
using namespace std;

//Good Question!!!

long long getPoints(vector<long long>& vals, vector<long long>& weights, int i, vector<long long>& dp){
    if (i >= vals.size()) return 0;
    if (dp[i] != -1) return dp[i];
    //You either notPick
    long long notPick = getPoints(vals, weights, i+1, dp);
    //You either pick
    auto it = upper_bound(vals.begin(), vals.end(), vals[i]+1);
    int j = it - vals.begin();
    long long pick = weights[i]*vals[i] + getPoints(vals, weights, j, dp);
    //If the next value exist
    long long maxi = max(pick, notPick);
    return dp[i] = maxi;
}

long long getMaxPoints(vector<int>& nums){
    map<int, int> mpp;
    for (int& num : nums) mpp[num]++;
    vector<long long> vals;
    vector<long long> weights;
    for (auto& it : mpp){
        vals.push_back(it.first);
        weights.push_back(it.second);
    }
    //Now this is just a knapsack problem with a special condition
    int sz = vals.size();
    vector<long long> dp (sz, -1);
    //dp[i] --> maxpoints you can get from i to sz-1
    return getPoints(vals, weights, 0, dp);
}

int main(){
    int n; cin >> n;
    vector<int> nums;
    for (int i=0; i<n; i++){
        int val; cin >> val;
        nums.push_back(val);
    }
    //Do not fuckin do careless mistakes (Wasted 30 min on the function, while the problem was in tyoe conversion)
    long long res = getMaxPoints(nums);
    cout << res << endl;
    return 0;
}