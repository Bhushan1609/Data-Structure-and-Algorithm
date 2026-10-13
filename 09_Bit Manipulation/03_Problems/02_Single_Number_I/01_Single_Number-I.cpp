// Problem Link : https://leetcode.com/problems/single-number/description/

#include<bits/stdc++.h>
using namespace std;

int missing_number(vector<int>&vec){
    int n=vec.size(),xorr=0;

    for(auto &num:vec)
        xorr^=num;

    return xorr;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,1,2,3,3,4,4};
    cout<<missing_number(vec)<<endl;
    return 0;
}