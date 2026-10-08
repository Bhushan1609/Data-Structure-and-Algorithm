//Problem Link : https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec,int k){
    int n=vec.size();
    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xorr=0;
            for(int k=i;k<=j;k++)
                xorr^=vec[k];
            if(xorr==k)
                cnt++;
        }
    }

    return cnt;
}

int call_better(vector<int>&vec,int k){
    int n=vec.size();
    int cnt=0;

    for(int i=0;i<n;i++){
        int xorr=0;
        for(int j=i;j<n;j++){
            xorr^=vec[j];
            if(xorr==k)
                cnt++;
        }
    }

    return cnt;
}

int call_optimal(vector<int>&vec,int k){            
    int n=vec.size();
    int cnt=0,xorr=0;
    unordered_map<int,int>mapp;
    mapp[xorr]=1;
    for(int i=0;i<n;i++){                           
        xorr^=vec[i];
        cnt+=mapp[xorr^k];
        mapp[xorr]+=1;
    }

    return cnt;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={4,2,2,6,4};
    int k=6;
    cout<<call_brute(vec,k)<<endl;
    cout<<call_better(vec,k)<<endl;
    cout<<call_optimal(vec,k)<<endl;

    return 0;
}