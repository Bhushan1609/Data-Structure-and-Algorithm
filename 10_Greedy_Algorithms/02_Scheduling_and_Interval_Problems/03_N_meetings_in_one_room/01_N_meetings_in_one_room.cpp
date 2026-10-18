// Problem Link : http://geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

#include<bits/stdc++.h>
using namespace std;

struct node{
    int start,end,pos;
};

bool comp(node a,node b){
    return a.end<b.end;
}

vector<int> maxMeetings(vector<int>&start,vector<int>&end){
    int n=start.size();
    vector<node>vec(n);

    for(int i=0;i<n;i++){                   // O(n)
        vec[i].start=start[i];
        vec[i].end=end[i];
        vec[i].pos=i+1;
    }

    sort(vec.begin(),vec.end(),comp);       // O(nlogn)

    int cnt=0,freeTime=vec[0].end;
    vector<int>ans={vec[0].pos};

    for(int i=1;i<n;i++){                   // O(n)
        if(vec[i].start>freeTime){
            cnt++;
            freeTime=vec[i].end;
            ans.push_back(vec[i].pos);
        }
    }
    
    sort(ans.begin(),ans.end());     // O(nlogn)
    return ans;
}                                           // O(2 * (n + logn))
                                            // SC- O(3*n) + O(n)
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>start={0,3,1,5,5,8},end={5,4,2,9,7,9};
    
    for(auto &num:maxMeetings(start,end))
        cout<<num<<" ";
    cout<<endl;


    return 0;
}