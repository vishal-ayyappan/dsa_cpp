#include <bits/stdc++.h>
using namespace std;

//Valid Anagram

bool isAnagram(string s, string t) {
    vector<int> characters1 (256, 0);
    vector<int> characters2 (256, 0);
    for (char& ch : s){
        int idx = int(ch);
        characters1[idx]++;
    }
    for (char& ch : t){
        int idx = int(ch);
        characters2[idx]++; 
    }
    for (int i=0; i<256; i++){
        if (characters1[i] != characters2[i]) return false;
    }
    return true;
}