#include<bits/stdc++.h>
using namespace std;

int iterative_binary_search(int target,vector<int>&vec){
    int n=vec.size();
    int low=0,high=n-1;

    while(low<=high){
        int mid=(low+(high-low)/2);
        if(vec[mid]==target)
            return mid;
        if(target<vec[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }

    return -1;
}

int recursion(int low,int high,int target,vector<int>&vec){
    if(low>=high)
        return -1;
    int mid=(low+(high-low)/2);
    if(vec[mid]==target){
        return mid;
    }else if(target<vec[mid]){
        return recursion(low,mid-1,target,vec);
    }else{
        return recursion(mid+1,high,target,vec);
    }
}

int recursive_binary_search(int target,vector<int>&vec){
    int n=vec.size();
    int low=0,high=n-1;
    return recursion(low,high,target,vec);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={3,4,6,7,9,12,16,17};
    cout<<iterative_binary_search(16,vec)<<endl;
    cout<<recursive_binary_search(16,vec)<<endl;
    return 0;
}