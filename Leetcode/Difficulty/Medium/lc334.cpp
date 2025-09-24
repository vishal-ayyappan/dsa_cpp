#include <bits/stdc++.h>
using namespace std;

//Increasing Triplet Subsequence

bool increasingTriplet(vector<int>& nums) {
    int num1 = INT_MAX;
    int num2 = INT_MAX;
    for (int num3 : nums){
        if (num3 <= num1) num1 = num3;
        else if (num3 <= num2) num2 = num3;
        else return true;  
    }
    return false;
}

//This can be done using brute force (n^3)
//This can be done using LIS (n^2)
//But this is the most optimal solution