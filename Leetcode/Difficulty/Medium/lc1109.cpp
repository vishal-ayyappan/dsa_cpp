#include <bits/stdc++.h>
using namespace std;

//Corporate Flight Bookings

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    //You would have to keep a map
    vector<int> flights (n+2, 0);
    int size = bookings.size();
    for (int i=0; i<size; i++){
        int start = bookings[i][0];
        int end = bookings[i][1];
        int seats = bookings[i][2];
        flights[start] += seats;
        flights[end+1] -= seats;
    }
    int sum = 0;
    for (int i=1; i<=n+1; i++){
        sum += flights[i];
        flights[i] = sum;
    }
    flights.erase(flights.begin());
    flights.erase(flights.end()-1);
    return flights;
}