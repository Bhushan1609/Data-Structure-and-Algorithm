// Problem Link : https://leetcode.com/problems/assign-cookies/description/

#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&greed,vector<int>&cookies){
    int i=0,j=0;
    int n=greed.size(),m=cookies.size();

    sort(greed.begin(),greed.end());                    // O(nlogn)
    sort(cookies.begin(),cookies.end());                // O(mlogm)
    
    while(i<n && j<m){                                  //O(min(n,m))
        if(cookies[j]>=greed[i])
            i++;
        j++;
    }
    return i;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>greed={1,5,3,3,4},cookies={4,2,1,2,1,3};
    cout<<find(greed,cookies)<<endl;
    return 0;
}