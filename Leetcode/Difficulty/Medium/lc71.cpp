#include <bits/stdc++.h>
using namespace std;

//Standard Stack Problem

//Instead of doing character wise, we will build directory wise
//The stack will store all the directory

string simplifyPath(string path) {
    int n = path.size();
    int i = 0;
    vector<string> directories;
    while (i < n){
        while (i < n && path[i] == '/') i++;
        string dir = "";
        while (i < n && path[i] != '/'){
            dir.push_back(path[i]);
            i++;
        }
        //Case 1
        if (dir == "" || dir == ".") continue;
        else if (dir == ".."){
            if (!directories.empty()) directories.pop_back();
        }
        else directories.push_back(dir);
    }
    string res = "/";
    for (int i=0; i<directories.size(); i++){
        res += directories[i];
        res += "/";
    }
    if (res.size() != 1) res.pop_back();
    return res;
}


//Another approach (Using string stream) [Tokenization]

string simplifyPath(string path) {
    int n = path.size();
    vector<string> directories;
    stringstream ss (path);
    string part;
    while (getline(ss, part, '/')){
        if (part == "" || part == ".") continue;
        else if (part == ".."){
            if (directories.size() != 0) directories.pop_back();
        }
        else directories.push_back(part);
    }
    string res = "/";
    for (int i=0; i<directories.size(); i++){
        res += directories[i];
        res += "/";
    }
    if (res.size() != 1) res.pop_back();
    return res;
}

