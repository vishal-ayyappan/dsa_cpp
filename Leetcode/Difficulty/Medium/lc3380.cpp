#include <bits/stdc++.h>
using namespace std;

//Brute Force

int maxRectangleArea(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 0)
        return -1;
    sort(points.begin(), points.end());
    int area = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // Bottom left and to left x should be same
                    // Top left and top right, x should be same
                    // For x coordinate
                    int x = -1;
                    int y = -1;
                    int bottomLeft_x = points[i][0];
                    int topLeft_x = points[j][0];
                    int bottomRight_x = points[k][0];
                    int topRight_x = points[l][0];
                    if (bottomLeft_x == topLeft_x &&
                        bottomRight_x == topRight_x) {
                        int x1_dist = abs(points[j][1] - points[i][1]);
                        int x2_dist = abs(points[l][1] - points[k][1]);
                        if (x1_dist == x2_dist)
                            x = x1_dist;
                    }
                    // for y coordinate
                    int bottomLeft_y = points[i][1];
                    int topLeft_y = points[j][1];
                    int bottomRight_y = points[k][1];
                    int topRight_y = points[l][1];
                    if (bottomLeft_y == bottomRight_y &&
                        topLeft_y == topRight_y) {
                        int y1_dist = abs(points[k][0] - points[i][0]);
                        int y2_dist = abs(points[l][0] - points[j][0]);
                        if (y1_dist == y2_dist)
                            y = y1_dist;
                    }
                    if (x == -1 || y == -1)
                        continue;
                    // No other points should be there in the rectangle
                    // other than these 4 points
                    bool doesPointExist = false;
                    for (int m = 0; m < n; m++) {
                        if ((points[m] == points[i]) ||
                            (points[m] == points[j]) ||
                            (points[m] == points[k]) ||
                            (points[m] == points[l]))
                            continue;
                        // If it is inside/border the rectangle
                        if (points[m][0] >= bottomLeft_x &&
                            points[m][0] <= topRight_x &&
                            points[m][1] >= bottomLeft_y &&
                            points[m][1] <= topRight_y) {
                            doesPointExist = true;
                        }
                    }
                    if (!doesPointExist)
                        area = max(area, x * y);
                }
            }
        }
    }
    if (area == INT_MIN)
        return -1;
    return area;
}

//TC - O(N^5)
//SC - O(1)