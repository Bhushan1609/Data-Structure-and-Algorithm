//Problem Link : https://leetcode.com/problems/fruit-into-baskets/description/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int call_brute(vector<int>&vec){
    int n=vec.size(),max_len(0);
    for(int i=0;i<n;i++){                       //O(n*n*logn)
        unordered_set<int>st;                   // SC-O(3)
        for(int j=i;j<n;j++){
            st.insert(vec[j]);
            if(st.size()<=2)
                max_len=max(max_len,j-i+1);
            else
                break;
        }
    }
    return max_len;
}

int call_optimal(vector<int>&vec){
    int n=vec.size(),max_len(0);
    int l=0,r=0;
    unordered_map<int,int>mapp;                         // O(3)

    while(r<n){                                         // O(2n)
        mapp[vec[r]]++;
        while(mapp.size()>2){
            mapp[vec[l]]--;
            if(mapp[vec[l]]==0)
                mapp.erase(vec[l]);
            l++;
        }
        max_len=max(max_len,r-l+1);
        r++;
    }

    return max_len;
}

int call_most_optimal(vector<int>&vec){
    int n=vec.size(),max_len(0);
    int l=0,r=0;    
    unordered_map<int,int>mapp;                                 // O(3)

    while(r<n){                                     // O(n)
        mapp[vec[r]]++;
        if(mapp.size()>2){
            mapp[vec[l]]--;
            if(mapp[vec[l]]==0)
                mapp.erase(vec[l]);
            l++;
        }else{
            max_len=max(max_len,r-l+1);
        }
        r++;
    }

    return max_len;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={3,3,3,1,2,1,1,2,3,3,4};
    cout<<call_brute(vec)<<endl;
    cout<<call_optimal(vec)<<endl;
    cout<<call_most_optimal(vec)<<endl;
    return 0;
}