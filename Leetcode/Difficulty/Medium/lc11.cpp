#include <bits/stdc++.h>
using namespace std;

//Container with most water (Can do it with 2 pointer approach)

int maxArea(vector<int>& height) {
    int maxi = INT_MIN;
    int n = height.size();
    int i = 0;
    int j = n-1;
    while (i < j){
        int breadth = j-i;
        int length;
        if (height[i] > height[j]) {
            length = height[j];
            j--;
        }
        else {
            length = height[i];
            i++;
        }
        int area = length * breadth;
        maxi = max(maxi, area);
    }
    return maxi;
}