#include<bits/stdc++.h>
using namespace std;

bool funct(int mid,vector<int>&bloomDay,int m,int k){
    int ans=0,cnt=0;
    int n=bloomDay.size();
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=mid){
            cnt++;
        }else{
            ans+=(cnt/k);
            cnt=0;
        }
    }
    ans+=(cnt/k);
    return ans=m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int low=1,high=1,ans=-1;
    for(auto &num:bloomDay)
        high=max(high,num);
    while(low<=high){
        int mid=low-(low-high)/2;
        if(funct(mid,bloomDay,m,k)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;        
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>bloomDay={7,7,7,7,13,11,12,7};
    int m=2,k=3;
    cout<<minDays(bloomDay,m,k)<<endl;
    return 0;
}