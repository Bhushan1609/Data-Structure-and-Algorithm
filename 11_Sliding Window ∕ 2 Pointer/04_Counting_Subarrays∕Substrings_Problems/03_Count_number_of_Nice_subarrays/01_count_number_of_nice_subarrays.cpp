//Problem Link : https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec,int k){
    int n=vec.size(),cnt=0,sum=0;

    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=vec[j]%2;
            cnt+=(sum==k);
        }
    }
    return cnt;
}

int solve(vector<int>&vec,int k){
    if(k<0)
        return 0;
    int n=vec.size(),cnt=0,sum=0;
    int l=0,r=0;

    while(r<n){                                     // O(2n)
        sum+=vec[r]%2;
        while(sum>k){
            sum-=vec[l]%2;
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

    vector<int>vec={1,1,2,1,1};
    int k=3;
    cout<<call_brute(vec,k)<<endl;
    cout<<call_optimal(vec,k)<<endl;
    return 0;
}