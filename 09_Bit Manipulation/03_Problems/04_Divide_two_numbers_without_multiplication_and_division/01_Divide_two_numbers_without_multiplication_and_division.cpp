// Problem Link : https://leetcode.com/problems/divide-two-integers/description/

#include<bits/stdc++.h>
using namespace std;

int divide(int dividend,int divisor){
    if(dividend==divisor)
        return 1;
    bool sign=true;
    sign&=(((dividend>0 && divisor<0) || (dividend<0 && divisor>0))?false:true);
    long n=(dividend);
    long d=(divisor);
    long quotient=0;
    n=abs(n);
    d=abs(d);
    while(n>=d){                                    // log(n) * log(n)
        int cnt=0;
        while(n>=(d<<(cnt+1)))
            cnt++;
        quotient+=(1<<cnt);
        n-= (d<<cnt);
    }

    if(quotient==(1<<31))
        return (sign?INT_MAX:INT_MIN);

    return (sign?quotient:-quotient);
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cout<<divide(22,3)<<endl;
    return 0;
}