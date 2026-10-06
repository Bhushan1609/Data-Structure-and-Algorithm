//Problem Link : https://leetcode.com/problems/maximum-product-subarray/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec){
    int n=vec.size();
    int max_prod=INT_MIN;
    for(int i=0;i<n;i++){                                       // O(n*n*n)
        for(int j=i;j<n;j++){
            int prod=1;
            for(int k=i;k<=j;k++)
                prod*=vec[k];
            max_prod=max(max_prod,prod);
        }
    }
    return max_prod;
}

int call_better(vector<int>&vec){
    int n=vec.size();
    int max_prod=INT_MIN;
    for(int i=0;i<n;i++){                                     // O(n*n)
        int prod=1;
        for(int j=i;j<n;j++){
            prod*=vec[j];
            max_prod=max(max_prod,prod);
        }
    }
    return max_prod;
}

int call_optimal(vector<int>&vec){
    int n=vec.size();
    int prefix=1,suffix=1,maxi=INT_MIN;

    for(int i=0;i<n;i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix*=vec[i];
        suffix*=vec[n-i-1];
        maxi=max({maxi,prefix,suffix});
    }
    return maxi;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={2,3,-2,4};
    cout<<call_brute(vec)<<endl;
    cout<<call_better(vec)<<endl;
    cout<<call_optimal(vec)<<endl;
    return 0;
}