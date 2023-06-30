#include<bits/stdc++.h>
using namespace std;

// Kth smallest element in an array using heap
int findKthSmallest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap;

    for (int num : nums) {
        maxHeap.push(num);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

// Median for infinite integers
double findMedian(vector<int>& nums) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
    return 0.0;
}

int main() {
    vector<int> nums = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int kthSmallest = findKthSmallest(nums, k);
    cout << "The " << k << "th smallest element is: " << kthSmallest << endl;

    double median = findMedian(nums);
    cout << "The median is: " << median << endl;

    return 0;
}
