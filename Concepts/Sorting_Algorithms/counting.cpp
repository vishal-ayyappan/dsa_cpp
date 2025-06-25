#include <bits/stdc++.h>
using namespace std;

// You use counting sort if there are duplicates and if the range of values in the array is small
// and if there exists no negative values

//Store frequency of the number
// And print the number, for 'frequency of number times'

//Typical use case for counting sort
string countSort(string arr) {
    vector<int> count (26, 0);
    string res;
    for (int i=0; i<arr.size(); i++){
        count[arr[i] - 'a']++;
    }
    for (int i=0; i<count.size(); i++){
        while (count[i] != 0){
            res.push_back(char('a'+i));
            count[i]--;
        }
    }
    return res;
}

//TC - O(N) + O(N*K) --> Worst Case
//SC - O(K)

