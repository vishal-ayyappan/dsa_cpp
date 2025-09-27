#include <bits/stdc++.h>
using namespace std;

//Registration system
int main(){
    int n; cin >> n;
    unordered_map<string, int> mpp;
    while (n > 0){
        string res;
        cin >> res;
        //If it is not in the map
        if (mpp.find(res) == mpp.end()){
            mpp[res] = 1;
            cout << "OK" << endl;
        }
        //If it already present in the map
        else{
            string temp = res + to_string(mpp[res]);
            mpp[res]++;
            cout << temp << endl;
        }
        n--;
    }
}