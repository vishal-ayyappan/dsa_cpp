#include <bits/stdc++.h>
using namespace std;

//This is similar to finding the maximum area of the histogram

vector<int> getNse(vector<int>& hist){
    int n = hist.size();
    vector<int> ans (n);
    stack<int> st;
    for (int i=n-1; i>=0; i--){
        //Increasing monotonic stack
        while (!st.empty() && hist[i] < hist[st.top()]){
            st.pop();
        }
        if (st.empty()) ans[i] = n;
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> getPse(vector<int>& hist){
    int n = hist.size();
    vector<int> ans (n);
    stack<int> st;
    for (int i=0; i<n; i++){
        //Increasing monotonic stack
        while (!st.empty() && hist[i] < hist[st.top()]){
            st.pop();
        }
        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int getMaxArea(vector<int>& hist){
    //Find the next and previous smaller element index for each value
    int n = hist.size();
    vector<int> nse = getNse(hist);
    vector<int> pse = getPse(hist);
    int maxArea = 0;
    for (int i=0; i<n; i++){
        int width = nse[i] - pse[i] - 1;
        int height = hist[i];
        int area = height*width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> hist (m);
    int maxVal = 0;
    for (int i=0; i<n; i++){
        //Having a prefix sum for the length of the histogram
        for (int j=0; j<m; j++){
            if (matrix[i][j] == '1') hist[j] += 1;
            else hist[j] = 0;
        }
        int area = getMaxArea(hist);
        maxVal = max(maxVal, area);
    }
    return maxVal;
}

//TC - O(N*4M)
//SC - O(2M)