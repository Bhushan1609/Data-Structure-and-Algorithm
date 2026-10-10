//Problem Link : https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec,int k){
    int n=vec.size(),max_len(0);

    for(int i=0;i<n;i++){                       // O(n*n)
        int zeros(0);
        for(int j=i;j<n;j++){
            zeros+=(vec[j]==0);
            if(zeros<=k){
                max_len=max(max_len,j-i+1);
            }
        }
    }
    return max_len;
}

int call_optimal(vector<int>&vec,int k){
    int n=vec.size(),max_len(0);
    int l=0,r=0,zeros(0);
    
    while(r<n){                         //.. O(2n)
        zeros+=(vec[r]==0);
        while(zeros>k){
            if(vec[l]==0)
                zeros--;
            l++;
        }   
        
        max_len=max(max_len,r-l+1);
        r++;
    }
    return max_len;
}

int call_most_optimal(vector<int>&vec,int k){
    int n=vec.size(),max_len(0);
    int l=0,r=0,zeros(0);
    
    while(r<n){                             // O(n)
        zeros+=(vec[r]==0);
        if(zeros>k){
            if(vec[l]==0)
                zeros--;
            l++;
        }else  
            max_len=max(max_len,r-l+1);
        r++;
    }
    return max_len;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<call_brute(vec,k)<<endl;
    cout<<call_optimal(vec,k)<<endl;
    cout<<call_most_optimal(vec,k)<<endl;
    return 0;
}