#include <bits/stdc++.h>
using namespace std;

//ZigZag Conversion
string convert(string s, int numRows) {
    int n = s.length();
    if (numRows == 1) return s;
    string res;
    //The gaps have a pattern
    int gap1 = (numRows-1)*2;
    int gap2 = 0;
    //Every row gap reduces by 2 and the next element gap increases by 2;
    int i = 0;
    while (i < numRows){
        int j = i;
        if (gap2 == 0){
            while (j < n){
                res.push_back(s[j]);
                j += gap1;
            }
        }
        else{
            while (j < n){
                res.push_back(s[j]);
                j += gap1;
                if (j < n){
                    res.push_back(s[j]);
                    j += gap2;
                }
            }
        }
        gap1 -= 2;
        gap2 += 2;
        if (gap2 == (numRows-1)*2){
            swap(gap1, gap2);
        }
        i++;
    }
    return res;
}

//TC - O(N)
//SC - O(1)