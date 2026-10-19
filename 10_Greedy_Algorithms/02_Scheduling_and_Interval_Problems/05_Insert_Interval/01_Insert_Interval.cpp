// Problem Link : https://leetcode.com/problems/insert-interval/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>insert(vector<vector<int>>&intervals,vector<int>&newInterval){
    int n=intervals.size();
    int i=0;
    vector<vector<int>>res;

    while(i<n && intervals[i][1]<newInterval[0])
        res.push_back(intervals[i++]);
    
    while(i<n && intervals[i][0]<=newInterval[1]){
        newInterval[0]=min(newInterval[0],intervals[i][0]);
        newInterval[1]=max(newInterval[1],intervals[i][1]);
        i++;
    }

    res.push_back(newInterval);

    while(i<n)
        res.push_back(intervals[i++]);

    return res;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>intervals={
        {1,3},
        {6,9}
    };
    vector<int>newInterval={2,5};
    
    for(auto &vec:insert(intervals,newInterval)){
        for(auto &num:vec)
            cout<<num<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}