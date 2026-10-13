// Problem Link : https://leetcode.com/problems/jump-game/description/

#include<bits/stdc++.h>
using namespace std;

bool reachEnd(vector<int>&vec){
    int n=vec.size(),maxIndex=0;

    for(int i=0;i<n;i++){
        if(i>maxIndex)
            return false;
        maxIndex=max(maxIndex,i+vec[i]);
    }
    return true;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={2,3,1,0,4};
    if(reachEnd(vec))
        cout<<"Reached the end of the array."<<endl;
    else
        cout<<"Not able to Reach the end of the array."<<endl;
    return 0;
}