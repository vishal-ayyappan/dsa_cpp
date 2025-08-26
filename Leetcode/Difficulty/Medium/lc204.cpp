#include <bits/stdc++.h>
using namespace std;

//Count Primes
int countPrimes(int n) {
    //Have to count the prime numbers strictly less than n
    vector<bool> arr (n+1, true);
    int limit = sqrt(n);
    for (int i=2; i<=limit; i++){
        int start = i*i;
        for (int j=start; j<=n; j+=i){
            arr[j] = false;
        }
    }
    int count = 0;
    for (int i=2; i<n; i++){
        if (arr[i]) count++;
    }
    return count;
}