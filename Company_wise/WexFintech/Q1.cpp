#include <bits/stdc++.h>
using namespace std;

string convToString(int num){
    if (num == 0) return "0";
    string temp = "";
    bool isPositive = true;
    if (num < 0) isPositive = false;
    int val = abs(num);
    while (val> 0){
        int dig = val%10;
        val = val/10;
        char ch = (char)(dig + '0');
        temp = string(1, ch) + temp;
    }
    if (!isPositive){
        temp = "-" + temp;
    }
    return temp;
}

void getCookies(vector<int>& cookies, int wt){
    string res = "";
    int ans = -1;
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = cookies.size();
    //Push it in the queue
    for (int i=0; i<n; i++){
        pq.push(cookies[i]);
    }
    int count = 1;
    int first_val = pq.top(); pq.pop();
    if (first_val == wt) ans = count;
    string temp = convToString(first_val);
    res = "[" + temp + "]";
    while (!pq.empty()){
        count++;
        int val1 = pq.top(); pq.pop();
        string temp1 = convToString(val1);
        string temp2 = "";
        if (val1 == wt) ans = count;
        if (!pq.empty()){
            int val2 = pq.top(); pq.pop();
            temp2 = convToString(val2);
            if (val2 == wt) ans = count;
        }
        res = "[" + temp1 + res + temp2 + "]";
    }
    cout << res << endl;
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while (t > 0){
        int n; cin >> n;
        vector<int> cookies;
        for (int i=0; i<n; i++){
            int x; cin >> x;
            cookies.push_back(x);
        }
        int wt; cin >> wt;
        getCookies(cookies, wt);
        t--;
    }
    return 0;
}