#include<bits/stdc++.h>
using namespace std;

// Merge Intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n=intervals.size();
    if(n==1)return intervals;
    sort(intervals.begin(),intervals.end());
    int cnt=1;
    for(int i=1;i<n;i++){
        if(intervals[i][0]<=intervals[cnt-1][1]){
            intervals[cnt-1]={min(intervals[cnt-1][0],intervals[i][0]),max(intervals[i][1],intervals[cnt-1][1])};    
        } else{
            intervals[cnt]={intervals[i][0],intervals[i][1]};
            cnt++;
            }
        }
    vector<vector<int>> ans;
    for(int i=0;i<cnt;i++){
        ans.push_back(intervals[i]);
    }
    return ans;
}

// Top K most frequent elements
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int n =nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto it: mp){
        pq.push({it.second,it.first});
    }
    vector<int> v;
    while(k--){
        v.push_back(pq.top().second);
        pq.pop();
    }
    return v;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> merged = merge(intervals);

    cout<<"Merged Intervals: "<< endl;
    for(auto it : merged) {
        cout<<"["<< it[0] << ", "<< it[1] <<"] " <<endl;
    }
    cout<<endl;

    vector<int> arr = {1,2,1,3,4,5,6,1,2,4,2,1,4,1,2,2,1,2,3};
    vector<int> ans = topKFrequent(arr, 3);
    cout<<"Top K frequent elements: ";
    for(auto it : ans) {
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}
