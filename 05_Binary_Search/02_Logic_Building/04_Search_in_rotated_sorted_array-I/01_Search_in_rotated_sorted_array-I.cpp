#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&vec,int target) {
    int low=0,high=vec.size()-1;
    while(low<=high){
        int mid=low-(low-high)/2;
        if(vec[mid]==target)
            return mid;
        else if(vec[low]<=vec[mid]){
            if(vec[low]<=target && target<=vec[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }

        }else if(vec[mid]<=vec[high]){
            if(vec[mid]<=target && target<=vec[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={7,8,9,1,2,3,4,5,6};
    int target=1;
    cout<<search(vec,target)<<endl;
    return 0;
}