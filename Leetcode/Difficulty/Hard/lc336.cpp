#include <bits/stdc++.h>
using namespace std;

//Palindrome Pairs
// Left + Mid and Right
// Left and Mid + Right

bool isPalindrome(string& s, int start, int end){
    while (start < end){
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    int n = words.size();
    //Each word is unique
    int emptyIdx = -1;
    vector<int> palindrome_str;
    unordered_map<string, int> mpp;
    //If one string is empty and the other is palindrome, the concatenated string is still palindrome
    for (int i=0; i<n; i++){
        if (words[i] == "") {
            emptyIdx = i;
            continue;
        }
        if (isPalindrome(words[i], 0, words[i].length()-1)) palindrome_str.push_back(i);
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        mpp[rev] = i;
    }
    for (int i=0; i<n; i++){
        for (int cut=0; cut<words[i].length(); cut++){
            //Getting left + mid
            //mid would be from cut to n-1
            string left = words[i].substr(0, cut);
            if (isPalindrome(words[i], cut, words[i].length()-1)){
                if (mpp.find(left) != mpp.end()){
                    if (i != mpp[left]) ans.push_back({i, mpp[left]});
                }
            }
            //Getting mid + right
            string right = words[i].substr(cut);
            if (isPalindrome(words[i], 0, cut-1)){
                if (mpp.find(right) != mpp.end()){
                    if (i != mpp[right]) ans.push_back({mpp[right], i});
                }
            }
        }
    }
    //If there exists an empty index
    if (emptyIdx != -1){
        for (auto& idx : palindrome_str){
            ans.push_back({idx, emptyIdx});
            ans.push_back({emptyIdx, idx});
        }
    }
    return ans;
}  