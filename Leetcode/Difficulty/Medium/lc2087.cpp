#include <bits/stdc++.h>
using namespace std;

//Minimum Cost Homecoming of a Robot in a Grid

//With everystep, you should move closer to the goal, and have to be greedy

//Greedy works because, you only have to move 2 out of 4 moves everytime, as for each step, you have to get closer to home.
//So you do not have to explore all the possiblities and hence greedy works.

int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int m = rowCosts.size();
    int n = colCosts.size();
    int i = startPos[0];
    int j = startPos[1];
    if (startPos[0] == homePos[0] && startPos[1] == homePos[1]) return 0;
    int minCost = 0;
    while (i != homePos[0] && j != homePos[1]){
        //Move bottom or right
        if (i < homePos[0] && j < homePos[1]){
            int cost1 = rowCosts[i+1];
            int cost2 = colCosts[j+1];
            minCost += min(cost1, cost2);
            if (cost1 > cost2) j++;
            else i++;
        }
        //Move bottom or left
        else if (i < homePos[0] && j > homePos[1]){
            int cost1 = rowCosts[i+1];
            int cost2 = colCosts[j-1];
            minCost += min(cost1, cost2);
            if (cost1 > cost2) j--;
            else i++;
        }
        //Move top or right
        else if (i > homePos[0] && j < homePos[1]){
            int cost1 = rowCosts[i-1];
            int cost2 = colCosts[j+1];
            minCost += min(cost1, cost2);
            if (cost1 > cost2) j++;
            else i--;
        }
        //Move top or left
        else{
            int cost1 = rowCosts[i-1];
            int cost2 = colCosts[j-1];
            minCost += min(cost1, cost2);
            if (cost1 > cost2) j--;
            else i--;
        }
    }
    // Column matched
    while (i != homePos[0]){
        if (i > homePos[0]){
            minCost += rowCosts[i-1];
            i--;
        }
        else{
            minCost += rowCosts[i+1];
            i++;
        }
    }
    // Row Matched
    while (j != homePos[1]){
        if (j > homePos[1]){
            minCost += colCosts[j-1];
            j--;
        }
        else{
            minCost += colCosts[j+1];
            j++;
        }
    }
    return minCost;
}