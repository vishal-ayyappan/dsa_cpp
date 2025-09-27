#include <bits/stdc++.h>
using namespace std;

//Can do using greedy and also dp

//1st approach greedy

bool comparePairs(const pair<long long, int>& a, const pair<long long, int>& b){
    return a.first > b.first;
}

long long getMaxScore(vector<pair<long long, int>>& skiing, vector<pair<long long, int>>& cinema, vector<pair<long long, int>>& board){
    int n = skiing.size();
    sort(skiing.begin(), skiing.end(), comparePairs); //To sort in descending order
    sort(cinema.begin(), cinema.end(), comparePairs);
    sort(board.begin(), board.end(), comparePairs);
    //get top 3 elements for each
    vector<pair<long long, int>> top_ski;
    vector<pair<long long, int>> top_cin;
    vector<pair<long long, int>> top_board;
    int i = 0;
    while (i < 3){
        top_ski.push_back(skiing[i]);
        top_cin.push_back(cinema[i]);
        top_board.push_back(board[i]);
        i++;
    }
    long long maxScore = 0;
    for (int i=0; i<3; i++){
        pair<long long, int> s = top_ski[i];
        for (int j=0; j<3; j++){
            pair<long long, int> c = top_cin[j];
            for (int k=0; k<3; k++){
                pair<long long, int> b = top_board[k];
                //If the days does not overlap then that is the answer
                if (s.second != c.second && c.second != b.second && b.second != s.second){
                    long long currScore = s.first + b.first + c.first;
                    maxScore = max(maxScore, currScore);
                }
            }
        }
    }
    return maxScore;
}

int main(){
    int t; cin >> t;
    while (t > 0){
        int n; cin >> n;
        vector<pair<long long, int>> skiing;
        for (int j=0; j<n; j++){
            int x; cin >> x;
            skiing.push_back({x, j});
        }
        vector<pair<long long, int>> cinema;
        for (int j=0; j<n; j++){
            int x; cin >> x;
            cinema.push_back({x, j});
        }
        vector<pair<long long, int>> board;
        for (int j=0; j<n; j++){
            int x; cin >> x;
            board.push_back({x, j});
        }
        long long maxScore = getMaxScore(skiing, cinema, board);
        cout << maxScore << endl;
        t--;
    }
    return 0;
}


//This would result in TLE

// int getMaximumSum(vector<vector<int>>& activities, int activity, vector<bool>& visited){
//     int n = activities[0].size();
//     if (activity == -1) return 0;
//     int maxi = 0;
//     for (int i=n-1; i>=0; i--){
//         if (!visited[i]){
//             visited[i] = true;
//             int val = activities[activity][i] + getMaximumSum(activities, activity-1, visited);
//             maxi = max(maxi, val);
//             visited[i] = false;
            
//         }
//     }
//     return maxi;
// }

// int getMaxSum(vector<vector<int>>& activities){
//     int m = activities.size();
//     int n = activities[0].size();
//     // dp[i][j] --> max Sum from day i to 0, given past activity is j
//     vector<bool> visited (n, false);
//     return getMaximumSum(activities, 2, visited);
// }

// int main(){
//     int t; cin >> t;
//     while (t > 0){
//         int n; cin >> n;
//         vector<vector<int>> activities;
//         for (int i=0; i<3; i++){
//             vector<int> ds;
//             for (int j=0; j<n; j++){
//                 int x; cin >> x;
//                 ds.push_back(x);
//             }
//             activities.push_back(ds);
//         }
//         int maxSum = getMaxSum(activities);
//         cout << maxSum << endl;
//         t--;
//     }
// }