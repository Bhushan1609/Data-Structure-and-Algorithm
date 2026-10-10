//Problem Link : https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec,int goal){
    int n=vec.size(),cnt=0,sum=0;

    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=vec[j];
            cnt+=(sum==goal);
        }
    }
    return cnt;
}

int solve(vector<int>&vec,int goal){
    if(goal<0)
        return 0;
    int n=vec.size(),cnt=0,sum=0;
    int l=0,r=0;

    while(r<n){                                     // O(2n)
        sum+=vec[r];
        while(sum>goal ){
            sum-=vec[l];
            l++;
        }
        cnt+=r-l+1;
        r++;
    }

    return cnt;
}

int call_optimal(vector<int>&vec,int goal){
    return solve(vec,goal)-solve(vec,goal-1);                                       // O(4n)
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,0,1,0,1};
    int goal=2;
    cout<<call_brute(vec,goal)<<endl;
    cout<<call_optimal(vec,goal)<<endl;
    return 0;
}