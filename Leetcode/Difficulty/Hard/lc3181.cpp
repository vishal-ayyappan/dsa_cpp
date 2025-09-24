#include <bits/stdc++.h>
using namespace std;


int maxTotalReward(vector<int>& rewardValues) {
    int n = rewardValues.size();
    sort(rewardValues.begin(), rewardValues.end());
    int maxVal = rewardValues.back();
    int maxPossible = 2*maxVal;
    vector<bool> dp (maxPossible+1, false);
    dp[0] = true;
    for (int r : rewardValues){
        for (int s = maxPossible-r;  s>=0; s--){
            if (dp[s] == true && r > s){
                dp[s+r] = true;
            }
        }
    }
    for (int i=maxPossible; i>=0; i++){
        if (dp[i]) return i;
    }
    return 0;
}