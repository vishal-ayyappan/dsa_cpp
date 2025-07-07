#include <bits/stdc++.h>
using namespace std;

//Greedy Algorithm

string removeDigit(string number, char digit) {
    int n = number.length();
    int count = 0;
    for (int i=0; i<n; i++){
        if (number[i] == digit){
            count++;
        }
    }
    for (int i=0; i<n; i++){
        if (number[i] == digit){
            if (number[i] < number[i+1]){
                number.erase(number.begin() + i);
                break;
            }
            else{
                count--;
                if (count == 0){
                    number.erase(number.begin() + i);
                    break;
                }
            }
        }
    }
    return number;
}