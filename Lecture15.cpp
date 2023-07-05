#include<bits/stdc++.h>
using namespace std;

// Function to build the segment tree
void buildSegmentTree(vector<int>& segmentTree, vector<int>& input, int low, int high, int pos) {
    if (low == high) {
        segmentTree[pos] = input[low];
        return;
    }
    int mid = (low + high) / 2;
    buildSegmentTree(segmentTree, input, low, mid, 2 * pos + 1);
    buildSegmentTree(segmentTree, input, mid + 1, high, 2 * pos + 2);
    segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
}

// Function to query the segment tree for range sum
int rangeSumQuery(vector<int>& segmentTree, int qlow, int qhigh, int low, int high, int pos) {
    if (qlow <= low && qhigh >= high) {
        return segmentTree[pos];
    }
    if (qlow > high || qhigh < low) {
        return 0;
    }
    int mid = (low + high) / 2;
    return rangeSumQuery(segmentTree, qlow, qhigh, low, mid, 2 * pos + 1) + rangeSumQuery(segmentTree, qlow, qhigh, mid + 1, high, 2 * pos + 2);
}

// Function to update a value in the segment tree
void updateValue(vector<int>& segmentTree, int low, int high, int index, int diff, int pos) {
    if (index < low || index > high) {
        return;
    }
    segmentTree[pos] += diff;
    if (low != high) {
        int mid = (low + high) / 2;
        updateValue(segmentTree, low, mid, index, diff, 2 * pos + 1);
        updateValue(segmentTree, mid + 1, high, index, diff, 2 * pos + 2);
    }
}

int main() {
    vector<int> input = {1, 3, 5, 7, 9, 11};
    int n = input.size();

    // Calculate the size of the segment tree
    int segmentTreeSize = 2 * pow(2, ceil(log2(n))) - 1;
    vector<int> segmentTree(segmentTreeSize);

    // Build the segment tree
    buildSegmentTree(segmentTree, input, 0, n - 1, 0);

    // Query the segment tree for range sum
    int qlow = 1, qhigh = 4;
    int sum = rangeSumQuery(segmentTree, qlow, qhigh, 0, n - 1, 0);
    cout << "Sum of elements in range [" << qlow << ", " << qhigh << "] is: " << sum << endl;

    // Update a value in the segment tree
    int index = 2, newValue = 6;
    int diff = newValue - input[index];
    input[index] = newValue;
    updateValue(segmentTree, 0, n - 1, index, diff, 0);

    // Query the segment tree again after update
    sum = rangeSumQuery(segmentTree, qlow, qhigh, 0, n - 1, 0);
    cout << "Sum of elements in range [" << qlow << ", " << qhigh << "] after update is: " << sum << endl;

    return 0;
}
