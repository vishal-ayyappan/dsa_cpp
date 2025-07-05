#include <bits/stdc++.h>
using namespace std;

/*
Get the sum of the first k, then subtract one from the end and add one from the back
*/

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int lsum = 0;
    int rsum = 0;
    for (int i=0; i<k; i++){
        lsum += cardPoints[i];
    }
    int maxSum = lsum;
    int idx = n-1;
    for (int i=k-1; i>=0; i--){
        lsum -= cardPoints[i];
        rsum += cardPoints[idx];
        maxSum = max(maxSum, lsum+rsum);
        idx--;
    }
    return maxSum;
}