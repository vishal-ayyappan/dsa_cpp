#include <bits/stdc++.h>
using namespace std;

//Asteroid Collision

//Elements in the stack should be either all -ve, all +ve or bottom -ve top +ve

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> ans;
    int i = 0;
    while (i < n){
        //if it is positive, push 
        if (asteroids[i] > 0) ans.push_back(asteroids[i]);
        //If it is negative
        else{
            while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])){
                ans.pop_back();
            }
            if (!ans.empty() && ans.back() == abs(asteroids[i])) ans.pop_back();
            else if (ans.empty() || ans.back() < 0) ans.push_back(asteroids[i]);
        }
        i++;
    }
    return ans;
}

//TC - O(N)
//SC - O(1)