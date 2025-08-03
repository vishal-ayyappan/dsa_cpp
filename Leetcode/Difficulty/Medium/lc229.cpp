#include <bits/stdc++.h>
using namespace std;

//Majority Element II (Extension of the Moores Voting Algo)

//Check for [4, 2, 1, 1] edge case

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int el1;
    int el2;
    bool el1_assgn = false;
    bool el2_assgn = false;
    int count1 = 0;
    int count2 = 0;
    int i = 0;
    while (i < n){
        //If the number is equal to element 1
        if (el1_assgn && el1 == nums[i]){
            count1++;
        }
        //If the number is equal to element 2
        else if (el2_assgn && el2 == nums[i]){
            count2++;
        }
        //If el1 not assigned
        else if (el1_assgn == false){
            el1 = nums[i];
            el1_assgn = true;
            count1 = 1;
        }
        //If el2 not assigned
        else if (el2_assgn == false){
            el2 = nums[i];
            el2_assgn = true;
            count2 = 1;
        }
        //If the number is not either
        else{
            count1--;
            count2--;
            if (count1 <= 0){
                count1 = 0;
                el1_assgn = false;
            }
            if (count2 <= 0){
                count2 = 0;
                el2_assgn = false;
            }
        }
        i++;
    }
    vector<int> ans;
    int occ1 = 0;
    int occ2 = 0;
    for (int i=0; i<n; i++){
        if (el1_assgn && nums[i] == el1) occ1++;
        if (el2_assgn && nums[i] == el2) occ2++;
    }
    if (occ1 > n/3) ans.push_back(el1);
    if (el1 == el2) return ans;
    if (occ2 > n/3) ans.push_back(el2);
    return ans;
}