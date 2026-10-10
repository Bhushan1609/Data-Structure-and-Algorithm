//Problem Link : https://leetcode.com/problems/subarrays-with-k-different-integers/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec,int k){
    int n=vec.size(),cnt=0;

    for(int i=0;i<n;i++){                               // O(n*n)
        unordered_set<int>st;
        for(int j=i;j<n;j++){
            st.insert(vec[j]);
            cnt+=(st.size()==k);
        }
    }
    return cnt;
}

int solve(vector<int>&vec,int k){
    if(k<0)
        return 0;
    int n=vec.size();
    int l=0,r=0,cnt=0;
    unordered_map<int,int>mapp;

    while(r<n){                                 // O(2n)
        mapp[vec[r]]++;
        while(mapp.size()>k){
            mapp[vec[l]]--;
            if(mapp[vec[l]]==0)
                mapp.erase(vec[l]);
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}

int call_optimal(vector<int>&vec,int k){
    return solve(vec,k)-solve(vec,k-1);                         // O(4n)
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,2,1,3,4};
    int k=3;
    cout<<call_brute(vec,k)<<endl;
    cout<<call_optimal(vec,k)<<endl;
    return 0;
}