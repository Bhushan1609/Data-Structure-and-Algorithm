#include<bits/stdc++.h>
using namespace std;

bool canWeplaceCows(int mid,vector<int>&arr,int k){
    int cnt=0,prev=-1;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(prev==-1){
            prev=arr[i];
            cnt++;
        }
        if(prev!=-1 && arr[i]-prev>=mid){
            cnt++;
            prev=arr[i];
        }
    }
    return cnt>=k;
}

int aggressiveCows(vector<int> &arr, int k) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int low=1,high=arr[n-1]-arr[0];
    int ans=-1;
    
    while(low<=high){
        int mid=low-(low-high)/2;
        if(canWeplaceCows(mid,arr,k)){
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

    vector<int>arr={0,3,4,7,10,9};
    int k=4;
    cout<<aggressiveCows(arr,k)<<endl;
    return 0;
}