#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int a=5,b=6;

    a = (a^b);
    b = (a^b); //  (a^b) ^ b
    a = (a^b); //   a ^ (a^b)

    cout<<a<<" "<<b<<endl;
    return 0;
}
