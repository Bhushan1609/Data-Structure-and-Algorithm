//Problem Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(string &s){
    int n=s.size(),cnt=0;

    for(int i=0;i<n;i++){                               // O(n*n)
        int hash[3]={0,0,0};
        for(int j=i;j<n;j++){
            hash[0]+=(s[j]=='a');
            hash[1]+=(s[j]=='b');
            hash[2]+=(s[j]=='c');
            if(hash[0]>0 && hash[1]>0 && hash[2]>0)
                cnt++;
        }
    }
    return cnt;
}

int call_optimal(string &s){
    int n=s.size(),cnt=0;
    int l=0,r=0,mini;
    int hash[3]={-1,-1,-1}; // last seen index;

    while(r<n){                                             // O(n)
        hash[s[r]-'a']=r;
        mini=min({hash[0],hash[1],hash[2]});
        if(mini!=-1)
            cnt+=mini+1;
        r++;
    }

    return cnt;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    string s="bbacba";
    cout<<call_brute(s)<<endl;
    cout<<call_optimal(s)<<endl;
    return 0;
}