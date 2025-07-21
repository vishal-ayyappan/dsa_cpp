#include <bits/stdc++.h>
using namespace std;

//Best Time to buy and sell stock

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 1) return 0;
    int buy = prices[0];
    int profit = INT_MIN;
    for (int i=1; i<n; i++){
        int sell = prices[i];
        buy = min(buy, prices[i]);
        profit = max(profit, sell-buy);
    }
    return profit;
}