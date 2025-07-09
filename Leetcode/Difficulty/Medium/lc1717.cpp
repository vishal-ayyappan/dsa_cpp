#include <bits/stdc++.h>
using namespace std;


int maximumGain(string s, int x, int y) {
    //If x > y, check ab and then check ba for max score.
    //If y > x, check ba and then check ab for max score.
    int n = s.length();
    int count = 0;
    if (x >= y) {
        string res;
        //Remove 'ab' first
        for (int i=0; i<n; i++){
            if (s[i] != 'b') res.push_back(s[i]);
            else{
                if (res.size() != 0 && res.back() == 'a') {
                    res.pop_back();
                    count += x;
                }
                else res.push_back(s[i]);
            }
        }
        //Remove 'ba' from the updated string
        string finalRes;
        for (int i=0; i<res.size(); i++){
            if (res[i] != 'a') finalRes.push_back(res[i]);
            else{
                if (finalRes.size() != 0 && finalRes.back() == 'b') {
                    finalRes.pop_back();
                    count += y;
                }
                else finalRes.push_back(res[i]);
            }
        }
    }
    else{
        string res;
        //Remove 'ba' first
        for (int i=0; i<n; i++){
            if (s[i] != 'a') res.push_back(s[i]);
            else{
                if (res.size() != 0 && res.back() == 'b') {
                    res.pop_back();
                    count += y;
                }
                else res.push_back(s[i]);
            }
        }
        //Remove 'ab' from the updated string
        string finalRes;
        for (int i=0; i<res.size(); i++){
            if (res[i] != 'b') finalRes.push_back(res[i]);
            else{
                if (finalRes.size() != 0 && finalRes.back() == 'a') {
                    finalRes.pop_back();
                    count += x;
                }
                else finalRes.push_back(res[i]);
            }
        }
    }
    return count;
}

//Approach 2 (Same as approach 1 but a bit cleaner)

int getScoreX(string& s, int x){
    string res;
    int n = s.length();
    int count = 0;
    for (int i=0; i<n; i++){
        if (s[i] != 'b') res.push_back(s[i]);
        else{
            if (res.size() != 0 && res.back() == 'a') {
                res.pop_back();
                count += x;
            }
            else res.push_back(s[i]);
        }
    }
    s = res;
    return count;
}

int getScoreY(string& s, int y){
    string res;
    int n = s.length();
    int count = 0;
    for (int i=0; i<n; i++){
        if (s[i] != 'a') res.push_back(s[i]);
        else{
            if (res.size() != 0 && res.back() == 'b') {
                res.pop_back();
                count += y;
            }
            else res.push_back(s[i]);
        }
    }
    s = res;
    return count;
}



int maximumGain(string s, int x, int y) {
    //If x > y, check ab and then check ba for max score.
    //If y > x, check ba and then check ab for max score.
    int n = s.length();
    int count = 0;
    if (x >= y) {
        int xscore = getScoreX(s, x);
        int yscore = getScoreY(s, y);
        count = xscore + yscore;
    }
    else{
        int yscore = getScoreY(s, y);
        int xscore = getScoreX(s, x);
        count = xscore + yscore;
    }
    return count;
}

//TC - O(N) + O(N)
//SC - O(N)
