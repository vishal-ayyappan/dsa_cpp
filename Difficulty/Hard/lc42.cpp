#include <bits/stdc++.h>
using namespace std;

/*
Compute the nge and pge for each element
Compute the max pge and nge for each element
*/

vector<int> getPge(vector<int>& height){
    int n = height.size();
    stack<int> st;
    vector<int> ans (n);
    ans[0] = -1;
    st.push(height[0]);
    int i = 1;
    while (i < n){
        int val = height[i];
        if (val <= st.top()){
            ans[i] = st.top();
            st.push(ans[i]);
        }
        else{
            while (!st.empty() && val > st.top()){
                st.pop();
            }
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(ans[i]);
        }
        i++;
    }
    return ans;
}

vector<int> getNge(vector<int>& height){
    int n = height.size();
    vector<int> ans (n);
    stack<int> st;
    ans[n-1] = -1;
    st.push(height[n-1]);
    int i = n-2;
    while (i >= 0){
        int val = height[i];
        if (val <= st.top()){
            ans[i] = st.top();
            st.push(ans[i]);
        }
        else{
            while (!st.empty() && val > st.top()){
                st.pop();
            }
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(ans[i]);
        }
        i--;
    }
    return ans;
}

vector<int> maxPGE(vector<int>& pge, vector<int>& height){
    int n = height.size();
    vector<int> maxPrefPge (n);
    int maxPge = INT_MIN;
    for (int i=0; i<n; i++){
        if (pge[i] == -1){
            if (height[i] > maxPge) maxPge = height[i];
        }
        else{
            if (pge[i] > maxPge) maxPge = pge[i];
        }
        maxPrefPge[i] = maxPge;
    }
    return maxPrefPge;
}

vector<int> maxNGE(vector<int>& nge, vector<int>& height){
    int n = height.size();
    vector<int> maxPrefNge (n);
    int maxNge = INT_MIN;
    for (int i=n-1; i>=0; i--){
        if (nge[i] == -1){
            if (height[i] > maxNge) maxNge = height[i];
        }
        else{
            if (nge[i] > maxNge) maxNge = nge[i];
        }
        maxPrefNge[i] = maxNge;
    }
    return maxPrefNge;
}

int trap(vector<int>& height) {
    int n = height.size();
    //Pre Computation
    vector<int> nge = getNge(height);
    vector<int> pge = getPge(height);
    vector<int> maxPge = maxPGE(pge, height);
    vector<int> maxNge = maxNGE(nge, height);
    int count = 0;
    for (int i=0; i<n; i++){
        if (maxPge[i] == height[i] || maxNge[i] == height[i]) continue;
        int minVal = min(maxPge[i], maxNge[i]);
        int counti = minVal - height[i];
        count += counti;
    }
    return count;
}

//TC - O(N) + O(N) + O(N) + O(N) + O(N)
//SC - O(4N) + O(2N)