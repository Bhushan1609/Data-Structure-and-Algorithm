#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    int low=1,high=x;
    int ans=0;
    while(low<=high){
        long mid=low-(low-high)/2;
        if(mid*mid<=x){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cout<<mySqrt(28)<<endl;
    return 0;
}