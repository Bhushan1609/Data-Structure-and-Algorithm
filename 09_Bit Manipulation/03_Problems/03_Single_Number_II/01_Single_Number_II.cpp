// Problem Link : https://leetcode.com/problems/single-number-ii/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec){
    int n=vec.size();
    unordered_map<int,int>mapp;

    for(auto &num:vec)                  // O(n*logm) where m is no of uniques element in vector
        mapp[num]++;

    for(auto &[i,j]:mapp)                           // O(m)
        if(j==1)
            return i;
    return -1;                              // SC - O(m)
}

int call_better(vector<int>&vec){
    int n=vec.size(),num=0;

    for(int i=0;i<32;i++){                                  // O(32*n)
        int cnt=0;
        for(auto &number:vec)
            cnt+=((number & (1<<i)) != 0);
        if(cnt%3==1)
            num=num | (1<<i);
    }
    return num;
}

int call_optimal(vector<int>&vec){
    int n=vec.size();

    sort(vec.begin(),vec.end());
    for(int i=1;i<n;i+=3)                               // O(nlogn) + O(n/3)
        if(vec[i]!=vec[i-1])
            return vec[i-1];
    return vec[n-1];
}

int call_most_optimal(vector<int>&vec){
    int n=vec.size(),ones=0,twos=0;

    for(int i=0;i<n;i++)                                    // O(n)
        ones=(ones^vec[i])&~twos,twos=(twos^vec[i])&~ones;
    return ones;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={5,5,5,6,4,4,4};
    cout<<call_brute(vec)<<endl;
    cout<<call_better(vec)<<endl;
    // cout<<call_optimal(vec)<<endl; // commenting bcaz func tampering the given data
    cout<<call_most_optimal(vec)<<endl;
    return 0;
}