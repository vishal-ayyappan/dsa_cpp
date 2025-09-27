//Bank Transactions
#include <bits/stdc++.h>
using namespace std;

//Have to keep the past values

//This one is conceptually correct
// int getMaxTransactions(vector<int>& nums, int i, int balance, vector<vector<int>>& dp){
//     if (i == nums.size()) return 0;
//     if (dp[i][balance] != -1) return dp[i][balance];
//     //You do not pick
//     int notPick = getMaxTransactions(nums, i+1, balance, dp);
//     int pick = 0;
//     if (balance + nums[i] >= 0) pick = 1 + getMaxTransactions(nums, i+1, balance + nums[i], dp);
//     dp[i][balance] = max(pick, notPick);
//     return dp[i][balance];
// }

// int maximizeTransactions(vector<int>& nums){
//     int n = nums.size();
//     int sum = 0;
//     for (int i=0; i<n; i++){
//         if (nums[i] > 0) sum += nums[i];
//     }
//     vector<vector<int>> dp (n, vector<int> (sum+1, -1));
//     //dp[i] --> max amount from i to n-1;
//     return getMaxTransactions(nums, 0, 0, dp);
// }

//But optimal solution (Priority queue + greedy)
int maximizeTransactions(vector<int>& nums){
    int n = nums.size();
    priority_queue<int> pq; //Max Heap (to take out the least -ve element when balance < 0)
    //If it is negative put it in the priority queue
    int balance = 0;
    int count = 0;
    for (int i=0; i<n; i++){
        balance += nums[i];
        count++;
        if (nums[i] < 0){
            pq.push(abs(nums[i]));
        }
        if (balance < 0){
            balance += pq.top();
            pq.pop();
            count--;
        }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while (t > 0){
        int n;
        cin >> n;
        vector<int> nums;
        for (int i=0; i<n; i++){
            int num; cin >> num;
            nums.push_back(num);
        }
        int res = maximizeTransactions(nums);
        cout << res;
        cout << " ";
        t--;
    }
    return 0;
}


