#include <bits/stdc++.h>
using namespace std;

//Sieve of Eratosthenes
vector<int> sieve(int n) {
    //Declare a size n+1 array
    vector<bool> arr (n+1, true);
    //Start from 2 and iterate until the sqrt of the number
    int limit = sqrt(n);
    for (int i=2; i<=limit; i++){
        //All the multiples of i, mark it as 1
        int start = i*i;
        for (int j=start; j<=n; j+=i){
            arr[j] = false;
        }
    }
    //Now, return the elements that are still marked false
    vector<int> ans;
    for (int i=2; i<=n; i++){
        if (arr[i]) ans.push_back(i);
    }
    return ans;
}