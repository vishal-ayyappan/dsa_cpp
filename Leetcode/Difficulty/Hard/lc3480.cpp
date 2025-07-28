#include <bits/stdc++.h>
using namespace std;

//Maximize Subarrays After Removing One Conflicting Pair (One of the hardest questions!! Check notes for intuition)

long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    //Store all the starting points for each ending point
    vector<vector<int>> mpp;
    int size = conflictingPairs.size();
    for (int i=0; i<size; i++){
        int start = conflictingPairs[i][0];
        int end = conflictingPairs[i][1];
        if (start > end) swap(start, end);
        mpp[end].push_back(start);
    }
    //Initializing the extra subarrays, (by removing any one of them)
    vector<long long> extras (n+1, 0);
    //Count all the valid subarrays
    long long total = 0;
    //For each ending point
    int maxConflictingPoint = 0;
    int secondMaxConfictingPoint = 0;
    for (int end=1; end<=n; end++){
        for (auto& u : mpp[end]){
            if (u >= maxConflictingPoint){
                secondMaxConfictingPoint = maxConflictingPoint;
                maxConflictingPoint = u;
            }
            else if (u >= secondMaxConfictingPoint){
                secondMaxConfictingPoint = u;
            }
        }
        total += end - maxConflictingPoint;
        extras[maxConflictingPoint] +=  maxConflictingPoint - secondMaxConfictingPoint;
    }
    long long maxExtra = *max_element(extras.begin(), extras.end());
    return total + maxExtra;
}

//TC - O(N)
//SC - O(N*N)