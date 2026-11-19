#include<bits/stdc++.h>
using namespace std;

bool funct(int mid,vector<int>&piles,int h){
    long long ans=0;
    int n=piles.size();
    for(int i=0;i<n;i++)
        ans+=ceil((double)piles[i]/(double)mid);
    return ans<=h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size(),ans=-1;
    int low=1,high=1;
    for(auto &num:piles)
        high=max(high,num);
    while(low<=high){
        int mid=low-(low-high)/2;
        if(funct(mid,piles,h)){
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

    vector<int>vec={3,6,7,11};
    int threshold=8;
    cout<<minEatingSpeed(vec,threshold)<<endl;
    return 0;
}