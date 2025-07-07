#include <bits/stdc++.h>
using namespace std;

//Online stock spanner

//Do the operations and then push

class StockSpanner {
private: 
    stack<pair<int, int>> st;
    void pge (stack<pair<int, int>>& st, int price){
        int count = 1;
        while (!st.empty() && price >= st.top().first){
            auto item = st.top();
            st.pop();
            int days = item.second;
            count = count + days;
        }
        st.push({price, count});
    }

public:
    StockSpanner() {}
    
    int next(int price) {
        pge(st, price);
        return st.top().second;
    }
};

//TC for each next call will be [Worst Case - O(N)]
//SC O(N)