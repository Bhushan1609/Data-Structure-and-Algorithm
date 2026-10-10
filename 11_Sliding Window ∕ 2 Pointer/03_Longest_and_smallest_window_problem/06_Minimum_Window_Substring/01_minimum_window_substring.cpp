//Problem Link : https://leetcode.com/problems/minimum-window-substring/description/

#include<bits/stdc++.h>
using namespace std;

string call_brute(string &s,string &t){
    int n=s.size(),m=t.size(),min_len=1e9,startInd=-1;

    for(int i=0;i<n;i++){                               // O(n*n)
        vector<int>hash(256,0);                         // O(256)
        int cnt=0;
        for(auto &ch:t)
            hash[ch]++;
        for(int j=i;j<n;j++){
            cnt+=(hash[s[j]]>0);
            hash[s[j]]--;
            if(cnt==m && j-i+1<min_len){
                min_len=j-i+1;
                startInd=i;
                break;
            }
        }
    }
    if(startInd==-1)
        return "";
    return s.substr(startInd,min_len);
}

string call_optimal(string &s,string &t){
    int n=s.size(),m=t.size(),min_len=1e9,startInd=-1;
    int l=0,r=0,cnt=0;
    vector<int>hash(256,0);

    for(auto &ch:t)                             // O(m)
        hash[ch]++;

    while(r<n){                                 // O(2n)
        cnt+=(hash[s[r]]>0);
        hash[s[r]]--;
        while(l<=r && cnt==m){
            if(r-l+1<min_len){
                min_len=r-l+1;
                startInd=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0)
                cnt--;
            l++;
        }
        r++;
    }

    if(startInd==-1)
        return "";
    return s.substr(startInd,min_len);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    string s="ddaaabbca",t="abc";
    cout<<call_brute(s,t)<<endl;
    cout<<call_optimal(s,t)<<endl;
    return 0;
}