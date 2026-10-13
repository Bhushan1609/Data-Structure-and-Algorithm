#include<bits/stdc++.h>
using namespace std;

void set_ith_bit(int &n,int i){         // Set ith bit
    n = n | (1<<i);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n=9;
    for(int i=0;i<32;i++){                  // Set the Unset ith bit from right
        if((n & (1<<i)) == 0){
            set_ith_bit(n,i);
            break;
        }
    }
    cout<<n<<endl;
    return 0;
}