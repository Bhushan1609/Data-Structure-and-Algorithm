// Problem Link : https://leetcode.com/problems/merge-intervals/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>&intervals){
    int n=intervals.size();
    vector<vector<int>>res;

    sort(intervals.begin(),intervals.end());

    vector<int>temp=intervals[0];

    for(auto &it:intervals){
        if(it[0]<=temp[1]){
            temp[1]=max(it[1],temp[1]);
        }
        else{
            res.push_back(temp);
            temp=it;
        }
    }
    res.push_back(temp);
    return res;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>intervals={
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };
    
    for(auto &vec:merge(intervals)){
        for(auto &num:vec)
            cout<<num<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}