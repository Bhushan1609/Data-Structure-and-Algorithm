#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low-(low-high)/2;
        int missing=arr[mid]-mid;
        if(missing>k){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    //arr[high]+k-(arr[high]-high-1) =arr[high]+k-arr[high]+high+1=k+high+1=low+k
    return low+k;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>arr={2,3,4,7,11};
    int k=5;
    cout<<findKthPositive(arr,k)<<endl;
    return 0;
}