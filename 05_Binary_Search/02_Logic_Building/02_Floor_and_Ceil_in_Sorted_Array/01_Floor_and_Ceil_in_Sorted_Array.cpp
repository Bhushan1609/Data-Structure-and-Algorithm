#include<bits/stdc++.h>
using namespace std;

int floor(int ele,vector<int>&vec){
    int n=vec.size(),ans=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid]<=ele){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int ceil(int ele,vector<int>&vec){
    int n=vec.size(),ans=n;
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(vec[mid]>=ele){
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
    cout<<floor(6,vec)<<endl; // <= ele
    cout<<ceil(6,vec)<<endl; // >= ele
    return 0;
}