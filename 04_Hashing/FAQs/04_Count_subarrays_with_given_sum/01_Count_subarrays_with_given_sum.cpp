//Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec,int k){
    int n=vec.size();
    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++)
                sum+=vec[k];
            if(sum==k)
                cnt++;
        }
    }

    return cnt;
}

int call_better(vector<int>&vec,int k){
    int n=vec.size();
    int cnt=0;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=vec[j];
            if(sum==k)
                cnt++;
        }
    }

    return cnt;
}

int call_optimal(vector<int>&vec,int k){            // this works in the case -ve 0 +ve (it is optimal for -ve)
    int n=vec.size();
    int cnt=0,sum=0;
    unordered_map<int,int>mapp;
    mapp[sum]=1;
    for(int i=0;i<n;i++){                           // O(nlogn)
        sum+=vec[i];
        cnt+=mapp[sum-k];
        mapp[sum]+=1;
    }

    return cnt;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,2,3,1,1,1,1,4,2,3};
    int k=3;
    cout<<call_brute(vec,k)<<endl;
    cout<<call_better(vec,k)<<endl;
    cout<<call_optimal(vec,k)<<endl;

    return 0;
}