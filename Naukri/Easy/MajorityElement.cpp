#include <bits/stdc++.h>
using namespace std;

//Majority voting (Moore's voting algo)

int findMajorityElement(int arr[], int n) {
	int i = 0;
    int element = arr[0];
    int count = 0;
    //To get the potential majority element
    while (i < n){
        if (arr[i] == element) count++;
        else count--;
        if (count < 0){
            element = arr[i];
            count = 1;
        }
        i++;
    }
    //If that element exists more than n/2 times, then that element is the majority element
    int occ = 0;
    for (int i=0; i<n; i++){
        if (arr[i] == element) occ++;
    }
    //If it is even, it should occur more than n/2 times
    if (occ > n/2) return element;
    return -1;
}