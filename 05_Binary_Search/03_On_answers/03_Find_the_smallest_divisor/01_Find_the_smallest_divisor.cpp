#include<bits/stdc++.h>
using namespace std;

bool funct(int mid,vector<int>&nums,int threshold){
    int ans=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
        ans+=ceil((double)nums[i]/(double)mid);
    return ans<=threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low=1,high=nums[0];
    int ans=-1;
    for(auto &num:nums)
        high=max(high,num);
    while(low<=high){
        int mid=low-(low-high)/2;
        if(funct(mid,nums,threshold)){
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

    vector<int>vec={1,2,5,9};
    int threshold=6;
    cout<<smallestDivisor(vec,threshold)<<endl;
    return 0;
}