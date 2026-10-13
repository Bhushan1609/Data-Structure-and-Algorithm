// Problem Link : https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

#include<bits/stdc++.h>
using namespace std;

int rangeXorr(int n){
    if(n%4==1)
        return 1;
    if(n%4==2)
        return n+1;
    if(n%4==3)
        return 0;
    return n;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int l=3,r=7;
    cout<<(rangeXorr(r)^rangeXorr(l-1))<<endl;
    return 0;
}