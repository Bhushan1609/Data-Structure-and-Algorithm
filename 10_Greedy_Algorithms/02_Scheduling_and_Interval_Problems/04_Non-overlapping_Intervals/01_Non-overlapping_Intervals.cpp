// Problem Link : https://leetcode.com/problems/non-overlapping-intervals/description/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int start,end,pos;
};

bool comp(node a,node b){
    return a.end<b.end;
}

int eraseOverlapIntervals(vector<vector<int>>&intervals){
    int n=intervals.size();
    vector<node>vec(n);

    for(int i=0;i<n;i++){                   // O(n)
        vec[i].start=intervals[i][0];
        vec[i].end=intervals[i][1];
    }

    sort(vec.begin(),vec.end(),comp);       // O(nlogn)

    int cnt=1,freeTime=vec[0].end;

    for(int i=1;i<n;i++){                   // O(n)
        if(vec[i].start>=freeTime){
            cnt++;
            freeTime=vec[i].end;
        }
    }
    
    return n-cnt;
}                                           // O(2*n + nlogn))
                                            // SC - O(2*n)
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>intervals={
        {1,2},
        {2,3},
        {3,4},
        {1,3}
    };
    
    cout<<eraseOverlapIntervals(intervals)<<" ";
    return 0;
}