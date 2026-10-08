//Problem Link : https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
//Only +ves    : https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec,int k){
    int n=vec.size();
    int max_len=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++)
                sum+=vec[k];
            if(sum==k)
                max_len=max(max_len,j-i+1);
        }
    }

    return max_len;
}

int call_better1(vector<int>&vec,int k){
    int n=vec.size();
    int max_len=0;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=vec[j];
            if(sum==k)
                max_len=max(max_len,j-i+1);
        }
    }

    return max_len;
}

int call_better2(vector<int>&vec,int k){            // this works in the case -ve 0 +ve (it is optimal for -ve)
    int n=vec.size();
    int max_len=0,sum=0;
    unordered_map<int,int>mapp;

    for(int i=0;i<n;i++){                           // O(nlogn)
        sum+=vec[i];
        if(sum==k)
            max_len=max(max_len,i+1);
        if(mapp.find(sum-k)!=mapp.end()){
            max_len=max(max_len,i-mapp[sum-k]);
        }
        if(mapp.find(sum)==mapp.end())              // SC - O(n)
            mapp[sum]=i;
    }

    return max_len;
}

int call_optimal(vector<int>&vec,int k){ // +vec and 0s
    int n=vec.size();
    int max_len=0;
    int i=0,j=0,sum=0;

    while(j<n){             // O(n)
        sum+=vec[j];
        while(i<=j && sum>k)
            sum-=vec[i++];
        if(sum==k)
            max_len=max(max_len,j-i+1);
        j++;
    }

    return max_len;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,2,3,1,1,1,1,4,2,3,-3};
    int k=0;
    cout<<call_brute(vec,k)<<endl;
    cout<<call_better1(vec,k)<<endl;
    cout<<call_better2(vec,k)<<endl;
    // cout<<call_optimal(vec,k)<<endl;

    return 0;
}