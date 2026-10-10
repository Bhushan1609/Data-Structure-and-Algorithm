//Problem Link : https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

#include<bits/stdc++.h>
using namespace std;

string call_brute(string &s,string &t){
    int n=s.size(),m=t.size(),min_len=1e9,startInd=-1;

    for(int i=0;i<n;i++){                               // O(n*n)
        int tindex=0;
        for(int j=i;j<n;j++){
            if(s[j]==t[tindex]){
                tindex++;
            }
            if(tindex==m){
                if(j-i+1<min_len){
                    min_len=j-i+1;
                    startInd=i;
                }
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
    int l=0,r=0;

    while(r<n){
        if (s[r]==t[l])
            l++;
        if (l==m){
            int end=r;
            l--;
            while(l>=0){
                if(s[r]==t[l])
                    l--;
                r--;
            }
            r++;
            if(end-r+1<min_len) {
                min_len=end-r+1;
                startInd=r;
            }    
            l=0;
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

    string s="geeksforgeeks",t="eksrg";
    cout<<call_brute(s,t)<<endl;
    cout<<call_optimal(s,t)<<endl;
    return 0;
}