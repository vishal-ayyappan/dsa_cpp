#include <bits/stdc++.h>
using namespace std;

//Shifting Letters II

//Same as the sweep line logic, but in this case, once you precompute all the shifts
// you keep a sum and iterate through the start to finish in the array.

string shiftingLetters(string s, vector<vector<int>>& shifts) {
    //Store all the shifts in the array, and then shift each character at the end.
    int n = s.length();
    vector<int> getShift (n);
    int size = shifts.size();
    for (int i=0; i<size; i++){
        int from = shifts[i][0];
        int to = shifts[i][1];
        int direction = shifts[i][2];
        //Shift forward
        if (direction == 1){
            getShift[from]++;
            getShift[to+1]--;
        }
        else{
            getShift[from]--;   
            getShift[to]++; 
        }
    }
    for (int i=1; i<n; i++){
        getShift[i] += getShift[i-1];
    }
    string ans;
    //Go through all the indices of the string
    for (int i=0; i<n; i++){
        int shiftBy = getShift[i] % 26;
        int idx = int(s[i] - 'a');
        idx += shiftBy;
        if (idx > 25) idx -= 26;
        if (idx < 0) idx += 26;
        char ch =  char(idx + 'a');
        ans.push_back(ch);
    } 
    return ans;  
}