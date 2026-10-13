#include<bits/stdc++.h>
using namespace std;
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n=16;
    if(n>0 && ((n & n-1) == 0))
        cout<<"Power or 2"<<endl;
    else
        cout<<"Not a Power or 2"<<endl;
    return 0;
}