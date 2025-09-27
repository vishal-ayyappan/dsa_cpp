#include <bits/stdc++.h>
using namespace std;

//Constructive Algo

bool isPresent(string& s){
    int n = s.length();
    int i = 0;
    vector<pair<int, int>> ab;
    vector<pair<int, int>> ba;
    while (i < n){
        string temp;
        bool isAB = false;
        bool isBA = false;
        temp.push_back(s[i]);
        int idx1 = i;
        int idx2 = -1;
        i++;
        if (i < n) {
            temp.push_back(s[i]);
            idx2 = i;
        }
        if (temp == "AB") {
            ab.push_back({idx1, idx2});
            isAB = true;
        }
        else if (temp == "BA") {
            ba.push_back({idx1, idx2});
            isBA = true;
        }
        //If you add any string in any of the buckets, then check condition
        if (isAB || isBA){
            if (ab.size() > 0 && ba.size() > 0){
                int m = ab.size();
                int n = ba.size();
                for (int i=0; i<m; i++){
                    int start_ab = ab[i].first;
                    int end_ab = ab[i].second;
                    for (int j=0; j<n; j++){
                        int start_ba = ba[j].first;
                        int end_ba = ba[j].second;
                        if (end_ab != start_ba && end_ba != start_ab) return true;
                    }
                }
            }
        }
    }
    return false;
}


int main(){
    string s;
    cin >> s;
    if (isPresent(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}