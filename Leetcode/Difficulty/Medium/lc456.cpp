#include <bits/stdc++.h>
using namespace std;

//132 Pattern


//Brute Force
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    for (int i=0; i<n-2; i++){
        for (int j=i+1; j<n-1; j++){
            for (int k=j+1; k<n; k++){
                if (nums[i] < nums[k] && nums[k] < nums[j]) return true;
            }
        }
    }
    return false;
}

//TC - O(N*N*N)
//SC - O(1)

//Better Approach
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    int mini = nums[0];
    for (int i=1; i<n-1; i++){
        mini = min(mini, nums[i]);
        for (int j=i+1; j<n; j++){
            if (mini < nums[j] && nums[j] < nums[i]) return true;
        }
    }
    return false;
}

//TC - O(N*N)
//SC - O(1)

//Optimal approach

//Traverse from the back, have a decreasing monotonic stack

//Intuition -> We need i < j < k and num[i] < num[k] < num[j]
//So, do num[k] < num[j] comparison first (Using the stack, while num[j] being secondlargest)

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    int secondLargest = INT_MIN;
    for (int i=n-1; i>=0; i--){
        if (nums[i] < secondLargest) return true;
        while (!st.empty() && nums[i] > st.top()){
            secondLargest = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}

//TC - O(N)
//SC - O(N)



