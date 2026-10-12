#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int num=10;//1010
    int i=1;

    //Using left shift operator
    cout<<(((1<<i) & num) != 0)<<endl;

    //Using right shift operator
    cout<<((num>>i) & 1)<<endl;
    return 0;
}