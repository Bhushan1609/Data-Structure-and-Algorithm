// Problem Link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

#include<bits/stdc++.h>
using namespace std;

int minFlipsCnt(int num1,int num2){
    int cnt=0;
    for(int i=0;i<32;i++)                                           // O(31)
        cnt+=((num1 & (1<<i)) != (num2 & (1<<i)) );
    return cnt;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int num1=10,num2=7;
    cout<<minFlipsCnt(num1,num2)<<endl; 
    return 0;
}