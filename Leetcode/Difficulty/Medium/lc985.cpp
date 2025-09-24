#include <bits/stdc++.h>
using namespace std;

//Sum of Even Numbers After Queries

vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    //Initially, get the sum of the even nums in the original array
    //Also, keep track of where the even numbers are
    int n = nums.size();
    vector<bool> isEven (n, false);
    int sum = 0;
    vector<int> ans;
    for (int i=0; i<n; i++){
        if (nums[i]%2 == 0){
            sum += nums[i];
            isEven[i] = true;
        }
    }
    //Now go through all the queries
    int m = queries.size();
    for (int i=0; i<m; i++){
        int value = queries[i][0];
        int idx = queries[i][1];
        if (isEven[idx]){
            int og_num = nums[idx];
            int new_num = og_num + value;
            sum -= og_num;
            if (new_num % 2 == 0){
                sum += new_num;
            }
            else isEven[idx] = false;
            nums[idx] = new_num;
        }
        else{
            int og_num = nums[idx];
            int new_num = og_num + value;
            //If the new number is even
            if (new_num % 2 == 0){
                sum += new_num;
                isEven[idx] = true;
            }
            nums[idx] = new_num;
        }
        ans.push_back(sum);
    }
    return ans;
}