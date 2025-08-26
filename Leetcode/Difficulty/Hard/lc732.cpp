#include <bits/stdc++.h>
using namespace std;

// My Calendar 3

class MyCalendarThree {
private:
    map<int, int> booking;
    int getK(){
        int sum = 0;
        int maxi = INT_MIN;
        for (auto& it : booking){
            sum += it.second;
            maxi = max(sum, maxi);
        }
        return maxi;
    }
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        booking[startTime]++;
        booking[endTime+1]--;
        return getK();
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */