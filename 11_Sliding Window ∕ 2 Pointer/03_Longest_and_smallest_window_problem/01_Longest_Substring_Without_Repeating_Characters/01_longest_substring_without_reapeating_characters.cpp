//Problem Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(string &s){
    int n=s.size();
    int max_len=0;

    for(int i=0;i<n;i++){                                           // O(n)
        int hash[255]={0};
        for(int j=i;j<n;j++){                                       // O(n)
            if(hash[s[j]]==1)
                break;
            max_len=max(max_len,j-i+1);
            hash[s[j]]++;
        }       
    }
    return max_len;                                                 // SC - O(255)
}

int call_optimal(string &s){
    int n=s.size(),max_len=0,l=0,r=0;
    int hash[255]={-1};                                 // SC - O(255)

    while(r<n){                                         // O(n)
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            max_len=max(max_len,r-l+1);
            hash[s[r]]=r;
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

    string s="cadbzabcd";
    cout<<call_brute(s)<<endl;
    cout<<call_optimal(s)<<endl;
    return 0;
}