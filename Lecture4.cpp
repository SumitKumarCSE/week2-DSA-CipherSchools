#include<bits/stdc++.h>
using namespace std;

// Next greater element in array
vector<int> nextGreaterElements(vector<int>& arr) {
    vector<int> res(arr.size());
    stack<int> stack;
    for (int i = arr.size() - 1; i >= 0; --i) {
        while (!stack.empty() && arr[stack.top()] <= arr[i]) {
            stack.pop();
        }
        res[i] = stack.empty() ? -1 : arr[stack.top()];
        stack.push(i);
    }
    return res;
}

// Next greater element in circular array
vector<int> nextGreaterElementsCircular(vector<int>& arr) {
    vector<int> res(arr.size());
    stack<int> stack;
    for (int i = 2 * arr.size() - 1; i >= 0; --i) {
        while (!stack.empty() && arr[stack.top()] <= arr[i % arr.size()]) {
            stack.pop();
        }
        res[i % arr.size()] = stack.empty() ? -1 : arr[stack.top()];
        stack.push(i % arr.size());
    }
    return res;
}

// Largest rectangle in histogram
int hgt [100001];
int pos [100001];
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int ans=heights[0], n=heights.size(), m=0;
    hgt[0]=heights[0];
    pos[0]=0;
    for(int i=1; i<n; ++i) {
        pos[m+1]=i;
        for(; m>=0 && heights [i]<hgt[m]; --m) {
            ans=max(ans,hgt[m]*(i-pos[m]));
        }
        hgt[++m]=heights[i];
    }
    return ans;
}

int main() {
    vector<int> arr = {2,3,4,12,2,6,7,11,1,6,10,5,3,9};
    vector<int> ans = nextGreaterElements(arr);
    cout<<"Next Greater Element: ";
    for(auto it : ans) {
        cout<<it<<" ";
    }
    cout<<endl;

    ans = nextGreaterElementsCircular(arr);
    cout<<"Next Greater Element in circular array: ";
    for(auto it : ans) {
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> heights = {2,1,5,6,2,3};
    cout<<"Largest Reantangle Area in Histogram: ";
    cout<<largestRectangleArea(heights)<<endl;

    return 0;
}
