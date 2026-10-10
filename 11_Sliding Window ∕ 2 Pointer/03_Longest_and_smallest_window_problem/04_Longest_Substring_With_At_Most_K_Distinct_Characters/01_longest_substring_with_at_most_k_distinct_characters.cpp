//Problem Link : https://www.naukri.com/code360/problems/distinct-characters_2221410

#include<bits/stdc++.h>
using namespace std;

int call_brute(string &s,int k){
    int max_len(0),n=s.size();

    for(int i=0;i<n;i++){                                   // O(n*n)
        unordered_map<char,int>hash;                        // SC - O(26)
        for(int j=i;j<n;j++){
            hash[s[j]]++;
            if(hash.size()<=k)
                max_len=max(max_len,j-i+1);
            else
                break;
        }
    }
    return max_len;
}

int call_optimal(string &s,int k){
    int max_len(0),n=s.size();
    int l=0,r=0;
    unordered_map<char,int>hash;                               // SC - O(26)
    while(r<n){                                                 // O(2n)
        hash[s[r]]++;
        while(hash.size()>k){
            hash[s[l]]--;
            if(hash[s[l]]==0)
                hash.erase(s[l]);
            l++;
        }
        max_len=max(max_len,r-l+1);
        r++;
    }
    return max_len;
}

int call_most_optimal(string &s,int k){
    int max_len(0),n=s.size();
    int l=0,r=0;
    unordered_map<char,int>hash;                    // SC - O(26)
    while(r<n){                                     // O(n)
        hash[s[r]]++;
        if(hash.size()>k){
            hash[s[l]]--;
            if(hash[s[l]]==0)
                hash.erase(s[l]);
            l++;
        }else if(hash.size()<=k)
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

    string s="aaabbccd";
    int k=2;
    cout<<call_brute(s,k)<<endl;
    cout<<call_optimal(s,k)<<endl;
    cout<<call_most_optimal(s,k)<<endl;
    return 0;
}