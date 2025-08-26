#include <bits/stdc++.h>
using namespace std;

// Ugly number 2

bool isUgly(int num){
    while (num > 0 && num%2 == 0) {
        num = num/2;
    }
    if (num == 1) return true;
    while (num > 0 && num%3 == 0) {
        num = num/3;

    }
    if (num == 1) return true;
    while (num > 0 && num%5 == 0) {
        num = num/5;

    }
    if (num == 1) return true;
    return false;
}

int uglNum(int num, int n){
    if (n == 0) return num-1;
    if (isUgly(num)) return uglNum(num+1, n-1);
    return uglNum(num+1, n);
}

int nthUglyNumber(int n) {
    return uglNum(1, n);
}

// Using DP (Very interesting approach)
int nthUglyNumber(int n) {
    vector<int> arr (n+1, 0);
    // arr[i] denotes the ith ugly number
    arr[1] = 1;
    int idx2 = 1;
    int idx3 = 1;
    int idx5 = 1;
    for (int i=2; i<=n;  i++){
        int num1 = arr[idx2]*2;
        int num2 = arr[idx3]*3;
        int num3 = arr[idx5]*5;
        int mini = min({num1, num2, num3});
        arr[i] = mini;
        if (mini == num1) idx2++;
        else if (mini == num2) idx3++;
        else idx5++;
    }
    return arr[n];
}


//You can also do this using priority queue, min heap, pop it k times. (Easy)
int nthUglyNumber(int n) {
    //Store the elements  (in the set)
    set<long long> s; //Min Heap
    s.insert(1);
    int count = 0;
    long long item;
    while (n > 0){
        item = *s.begin();
        s.erase(s.begin());
        // Get all the three numbers
        long long num1 = item*2;
        long long num2 = item*3;
        long long num3 = item*4;
        s.insert(num1);
        s.insert(num2);
        s.insert(num3);
        n--;
    }
    return (int)item;
}


