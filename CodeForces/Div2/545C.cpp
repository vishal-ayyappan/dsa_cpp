#include <bits/stdc++.h>
using namespace std;

long long getMaxTrees(vector<long long>& coordinates, vector<long long>& heights){
    //Coordinates
    int n = coordinates.size();
    coordinates.push_back(LONG_MAX);
    int count = 1;
    long long rightMost_occupied = coordinates[0];
    for (int i=1; i<n; i++){
        //Go left
        if (coordinates[i] - heights[i] > rightMost_occupied){
            rightMost_occupied = coordinates[i];
            count++;
        }
        //Go right
        else if (coordinates[i] + heights[i] < coordinates[i+1]){
            rightMost_occupied = coordinates[i] + heights[i];
            count++;
        }
        //If you cannot place anywhere
        else{
            rightMost_occupied = coordinates[i];
        }
    }
    return count;
}

int main(){
    int n; cin >> n;
    vector<long long> coordinates;
    vector<long long> heights;
    while (n > 0){
        long long coordinate; cin >> coordinate;
        long long height; cin >> height;
        coordinates.push_back(coordinate);
        heights.push_back(height);
        n--;
    }
    vector<long long> dp (n, -1);
    //dp[i] --> max trees you can get from i to n-1;
    long long maxTrees = getMaxTrees(coordinates, heights);
    cout << maxTrees << endl;
    return 0;
}