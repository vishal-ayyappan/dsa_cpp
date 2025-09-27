#include <bits/stdc++.h>
using namespace std;

//This is the brute way to find the lcm
// long long lcm(long long x, long long y){
//     if (x > y) return lcm(y, x);
//     long long i = 1;
//     while (true){
//         long long num = i*y;
//         if (num % x == 0) return num;
//         i++;
//     }
//     return -1;
//     //TC --> Worst Case O(min(x, y))
// }

//Optimal way to find the lcm == x*y/hcf(x,y)
long long lcm(long long x, long long y){
    //Finding gcd
    long long a = x;
    long long b = y;
    while (b != 0){
        if (a > b){
            long long temp = a%b;
            a = b;
            b = temp;
        }
        else{
            long long temp = b%a;
            b = temp;
        }
    }
    long long hcf = a;
    long long lcm = (x * y) / a;
    return lcm;
    //TC --> Worst Case O(log(min(x, y)))
}

long long getMaxVal(int n, long long x, long long y){
    //You have from 1 to n
    //Find the LCM of x and y
    long long p = lcm(x, y);
    long long no_x = n/x;
    long long no_y = n/y;
    long long no_p = n/p;
    no_x -= no_p;
    no_y -= no_p;
    // x - y should be maximum
    // while (no_x > 0){
    //     sum_x += i;
    //     i--;
    //     no_x--;
    // }
    // long long j = 1;
    // long long sum_y = 0;
    // while (no_y > 0){
    //     sum_y += j;
    //     j++;
    //     no_y--;
    // }
    //Can be done in O(1) complexity
    long long sum_x = (no_x * (2*n - no_x + 1))/2;
    long long sum_y = (no_y * (no_y + 1))/2;
    long long res = sum_x - sum_y;
    return res;
}

int main(){
    int t; cin >> t;
    while (t > 0){
        long long n; cin >> n;
        long long x; cin >> x;
        long long y; cin >> y;
        long long result = getMaxVal(n, x, y);
        cout << result << endl;
        t--;
    }
    return 0;
}