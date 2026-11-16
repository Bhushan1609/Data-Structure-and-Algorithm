#include<bits/stdc++.h>
using namespace std;

int lower_bound(int target,vector<int>&vec){
    int n=vec.size(),ans=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid]>=target){
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

    vector<int>vec={3,5,8,15,19};
    cout<<lower_bound(5,vec)<<endl;
    return 0;
}