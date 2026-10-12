#include<bits/stdc++.h>
using namespace std;

string convert2binary(int &n){                             // O(log2(n)) SC - O(log2(n))
    string binary="";

    while(n!=0)
        binary+=(n%2==0?'0':'1'),n>>=1;

    reverse(binary.begin(),binary.end());
    return binary;
}

int convert2decimal(string &binary){                        // O(n) SC - O(1)
    int ans=0,power=1;
    int n=binary.size();

    for(int i=n-1;i>=0;i--)
        ans+=((binary[i]=='1')?power:0),power*=2;
    
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n=13;
    string binary=convert2binary(n);
    cout<<binary<<endl;
    n=convert2decimal(binary);
    cout<<n<<endl;
    return 0;
}
