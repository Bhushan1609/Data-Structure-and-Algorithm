#include<bits/stdc++.h>
using namespace std;

int funct(int mid,int n,int m){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m)
            return 0;
    }
    if(ans==m)
        return 1;
    return 2;
}

int nthRoot(int n, int m) {
    if(m==0)
        return 0;
    int low=1,high=m;
    while(low<=high){
        int mid=low-(low-high)/2;
        int ans=funct(mid,n,m);
        if(ans==1){
            return mid;
        }else if(ans==0){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    cout<<nthRoot(3,27)<<endl;
    return 0;
}