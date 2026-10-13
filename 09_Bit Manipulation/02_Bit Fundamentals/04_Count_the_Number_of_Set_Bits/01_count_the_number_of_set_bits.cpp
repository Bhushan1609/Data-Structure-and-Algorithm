#include<bits/stdc++.h>
using namespace std;
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n=15,cnt=0;
    cout<<__builtin_popcount(n)<<endl; // O(31)   

    while(n>0)
        cnt+=(n&1),n>>=1;

    cout<<cnt<<endl; //log2(n) 
    return 0;
}