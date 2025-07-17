#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans (n+1, 0);
    for (int i=1; i<=n; i++){
        int count = 0;
        int num = i;
        while (num){
            count++;
            int j = num-1;
            num = num & j;
        }
        ans[i] = count;
    }
    return ans;
}