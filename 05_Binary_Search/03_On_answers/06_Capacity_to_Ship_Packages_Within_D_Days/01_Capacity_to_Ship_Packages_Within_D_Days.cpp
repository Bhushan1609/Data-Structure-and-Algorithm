#include<bits/stdc++.h>
using namespace std;

bool funct(int mid,vector<int>&weights,int days){
    int ans=0,day=1,cntWeight=0;
    int n=weights.size();
    for(int i=0;i<n;i++){
        cntWeight+=weights[i];
        if(cntWeight>mid){
            day++;
            cntWeight=weights[i];
        }
    }
    return day<=days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low=1,high=0,ans=-1;
    for(auto &num:weights){
        low=max(low,num);
        high+=num;
    }
    while(low<=high){
        int mid=low-(low-high)/2;
        if(funct(mid,weights,days)){
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

    vector<int>weights={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    cout<<shipWithinDays(weights,days)<<endl;
    return 0;
}