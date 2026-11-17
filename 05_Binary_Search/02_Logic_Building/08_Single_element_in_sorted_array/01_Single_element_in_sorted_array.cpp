#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& vec) {
    int n=vec.size();
    if(n==1)
        return vec[0];
    if(vec[0]!=vec[1])
        return vec[0];
    else if(vec[n-1]!=vec[n-2])
        return vec[n-1];
    int low=1,high=n-2;
    while(low<=high){
        int mid=low-(low-high)/2;
        if(vec[mid]!=vec[mid-1] && vec[mid]!=vec[mid+1]){
            return vec[mid];
        }else if((mid&1 && vec[mid]==vec[mid-1]) or (mid%2==0 && vec[mid]==vec[mid+1])){
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

    vector<int>vec={1,1,2,2,3,3,4,5,5,6,6};
    int target=1;
    cout<<singleNonDuplicate(vec)<<endl;
    return 0;
}