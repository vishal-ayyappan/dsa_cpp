#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//Sum of Infinite array
vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    //Online Queries
    vector<long long> prefix (n);
    prefix[0] = arr[0];
    for (int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    //Go through all the queries
    vector<int> ans (q);
    for (int i=0; i<q; i++){
        long long left = queries[i][0];
        long long quotient_left = (left-1) / n;
        long long rem_left = (left-1) % n;
        long long sumLeft = ((__int128)quotient_left % MOD * prefix[n-1] % MOD) % MOD;
        if (rem_left > 0) sumLeft += prefix[rem_left-1]%MOD;
        long long right = queries[i][1];
        long long quotient_right = right / n;
        long long rem_right = right % n;
        long long sumRight = ((__int128)quotient_right % MOD * prefix[n-1] % MOD) % MOD;
        if (rem_right > 0) sumRight += prefix[rem_right-1] % MOD;
        ans[i] = ((sumRight - sumLeft) % MOD + MOD) % MOD;

    }  
    return ans; 
}