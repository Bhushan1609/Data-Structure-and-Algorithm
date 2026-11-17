#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& vec) {
    int low=0,high=vec.size()-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high){
        int mid=low-(low-high)/2;
        if(vec[low]<=vec[mid]){
            if(ans>vec[low]){
                index=low;
                ans=vec[low];
            }
            low=mid+1;
        }else if(vec[mid]<=vec[high]){
            if(ans>vec[high]){
                index=high;
                ans=vec[high];
            }
            high=mid-1;
        }
    }     
    return index;   
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={4,5,6,7,0,1,2,3};
    int target=1;
    cout<<findMin(vec)<<endl;
    return 0;
}