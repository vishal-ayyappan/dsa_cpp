#include <bits/stdc++.h>
using namespace std;

//Find Median from Data Stream 

//Brute Force
class MedianFinder {
    multiset<int> ms;
public:
    MedianFinder() {
        ms.clear();
    }
    
    void addNum(int num) {
        ms.insert(num);
    }
    
    double findMedian() {
        int size = ms.size();
        auto it = ms.begin();
        int idx1 = -1;
        int idx2 = -1;
        long long val;
        if (size % 2 == 1) {
            idx1 = size/2;
            auto it1 = next(it, idx1);
            val = *it1;
        }
        else{
            idx1 = size/2;
            idx2 = idx1 + 1;
            auto it1 = next(it, idx1);
            auto it2 = next(it, idx2);
            val = (*it1 + *it2)/2;
        }
        return val;
    }
};

//Optimal
class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    MedianFinder() {
        //Empty both the heaps
        while (!max_heap.empty()) max_heap.pop();
        while (!min_heap.empty()) min_heap.pop();
    }
    
    void addNum(int num) {
        if (max_heap.empty() || max_heap.top() > num) max_heap.push(num);
        else min_heap.push(num);
    }
    
    double findMedian() {
        int left = max_heap.size();
        int right = min_heap.size();
        if (right > left){
            while (left <= right){
                int el = min_heap.top();
                min_heap.pop();
                max_heap.push(el);
                right--;
                left++;
            }
        }
        else if (left > right){
            while (left - right > 1){
                int el = max_heap.top();
                max_heap.pop();
                min_heap.push(el);
                left--;
                right++;
            }
        }
        if (left == right){
            double val1 = min_heap.top();
            double val2 = max_heap.top();
            return (val1+val2)/2;
        }
        else{
            double val1 = max_heap.top();
            return val1;
        }
    }
};