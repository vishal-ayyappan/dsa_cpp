#include <bits/stdc++.h>
using namespace std;

//Letter Combinations of a Phone Number
void getMapping(unordered_map<char, string>& mpp){
    for (char ch = 'a'; ch <= 'c'; ch++) mpp['2'].push_back(ch);
    for (char ch = 'd'; ch <= 'f'; ch++) mpp['3'].push_back(ch);
    for (char ch = 'g'; ch <= 'i'; ch++) mpp['4'].push_back(ch);
    for (char ch = 'j'; ch <= 'l'; ch++) mpp['5'].push_back(ch);
    for (char ch = 'm'; ch <= 'o'; ch++) mpp['6'].push_back(ch);
    for (char ch = 'p'; ch <= 's'; ch++) mpp['7'].push_back(ch);
    for (char ch = 't'; ch <= 'v'; ch++) mpp['8'].push_back(ch);
    for (char ch = 'w'; ch <= 'z'; ch++) mpp['9'].push_back(ch);
}

void getCombinations(string digits, int i, vector<string>& ans, string& ds, unordered_map<char, string>& mpp){
    if (i == digits.length()){
        ans.push_back(ds);
        return;
    } 
    char num = digits[i];
    for (char& ch : mpp[num]){
        ds.push_back(ch);
        getCombinations(digits, i+1, ans, ds, mpp);
        ds.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    //Map the characters that belong to each digit
    vector<string> ans;
    if (digits.length() == 0) return ans;
    string ds;
    unordered_map<char, string> mpp;
    getMapping(mpp);
    getCombinations(digits, 0, ans, ds, mpp);
    return ans;
}