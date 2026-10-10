//Problem Link : https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(string &s,int k){
    int n=s.size(),max_len=0,max_freq=0;

    for(int i=0;i<n;i++){                                                   // O(n*n)
        unordered_map<char,int>mapp;                                        // O(26)
        for(int j=i;j<n;j++){
            mapp[s[j]]++;
            max_freq=max(max_freq,mapp[s[j]]);
            if(j-i+1-max_freq<=k)
                max_len=max(max_len,j-i+1);
            else
                break;
        }
    }
    return max_len;
}


int call_optimal(string &s,int k){
    int n=s.size(),max_len=0,max_freq=0;
    int l=0,r=0;
    unordered_map<char,int>mapp;                                // O(26)

    while(r<n){                                                 //O(2n)
        mapp[s[r]]++;
        max_freq=max(max_freq,mapp[s[r]]);
        while(r-l+1-max_freq>k){
            mapp[s[l]]--;
            max_freq=0;
            for(auto &[i,j]:mapp)
                max_freq=max(max_freq,j);
            l++;
        }
        max_len=max(max_len,r-l+1);
        r++;
    }

    return max_len;
}


int call_most_optimal(string &s,int k){
    int n=s.size(),max_len=0,max_freq=0;
    int l=0,r=0;
    unordered_map<char,int>mapp;                                    //O(26)

    while(r<n){                                                         //O(n)
        mapp[s[r]]++;
        max_freq=max(max_freq,mapp[s[r]]);
        if(r-l+1-max_freq>k){
            mapp[s[l]]--;
            max_freq=0;
            for(auto &[i,j]:mapp)
                max_freq=max(max_freq,j);
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

    string s="AABABBA";
    int k=2;
    cout<<call_brute(s,k)<<endl;
    cout<<call_optimal(s,k)<<endl;
    cout<<call_most_optimal(s,k)<<endl;
    return 0;
}