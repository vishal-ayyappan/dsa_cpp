#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int n = bills.size();
    //Store 0, 10, 20 freq in an array
    int five = 0;
    int ten = 0;
    for (int i=0; i<n; i++){
        if (bills[i] == 5) five++;
        else if (bills[i] == 10){
            if (five >= 1){
                five--;
                ten++;
            }
            else return false;
        }
        else{
            //Two cases
            //1st priority
            if (five >= 1 && ten >= 1){
                ten--;
                five--;
            }
            else if (five >= 3){
                five -=3;
            }
            else return false;
        }
    }
    return true;
}

//We do not need to track twenty as we do not use it for change
//It is always better to give 10 and 5 rather than 3 5's if possible, in order to keep the 5 change.


//TC - O(N)
//SC - O(1)