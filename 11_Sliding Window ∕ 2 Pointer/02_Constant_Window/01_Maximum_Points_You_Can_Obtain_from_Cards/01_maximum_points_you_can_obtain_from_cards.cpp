//Problem Link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include<bits/stdc++.h>
using namespace std;

int giveMaxSum(vector<int>&vec,int k){
    int n=vec.size(),max_sum=0,lsum=0,rsum=0;
    for(int i=0;i<k;i++)                            // O(k)
        lsum+=vec[i];
    max_sum=max(max_sum,lsum);
    for(int i=k-1,rightInd=n-1;i>=0;i--,rightInd--){      // O(k)
        lsum-=vec[i];
        rsum+=vec[rightInd];
        max_sum=max(max_sum,lsum+rsum);
    }
    return max_sum;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={6,2,3,4,7,2,1,7,1};
    int k=4;
    cout<<giveMaxSum(vec,k)<<endl;
    return 0;
}