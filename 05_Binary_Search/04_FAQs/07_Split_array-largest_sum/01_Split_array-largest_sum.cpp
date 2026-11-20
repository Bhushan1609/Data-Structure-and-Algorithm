#include<bits/stdc++.h>
using namespace std;

bool fucnt(int mid,vector<int>&nums,int k){
    int cnt=0,sum=0,n=nums.size();
    cnt++;
    for(int i=0;i<n;i++){
        if(sum+nums[i]>mid){
            cnt++;
            sum=nums[i];
        }else{
            sum+=nums[i];
        }
    }
    return cnt>k;
}

int splitArray(vector<int>& nums, int k) {
    int low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0);
    while(low<=high){
        int mid=low-(low-high)/2;
        if(fucnt(mid,nums,k)){
            low=mid+1;
        }else{
            high=mid-1;
            
        }
    }
    return low;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>arr={25,46,28,49,24};
    int k=4;
    cout<<splitArray(arr,k)<<endl;
    return 0;
}