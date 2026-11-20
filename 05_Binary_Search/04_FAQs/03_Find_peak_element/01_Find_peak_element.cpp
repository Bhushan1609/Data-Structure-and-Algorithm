#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return 0;
    if(nums[0]>nums[1])        
        return 0;
        
    if(nums[n-1]>nums[n-2])
        return n-1;

    int low=1,high=n-2;
    while(low<=high){
        int mid=low-(low-high)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
            return mid;
        }else if(nums[mid-1]<nums[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>nums={1,2,3,4,5,6,7,8,5,1};
    cout<<findPeakElement(nums)<<endl;
    return 0;
}