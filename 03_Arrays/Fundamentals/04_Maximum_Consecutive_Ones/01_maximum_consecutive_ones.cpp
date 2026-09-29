//Problem-Link : https://leetcode.com/problems/max-consecutive-ones/description/

#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={1,1,0,1,1,1,0,1,1};
    int cnt=0,temp_cnt=0,n=vec.size();
    
    for(int i=0;i<n;i++){                                   // O(n)
        if(vec[i]==1){
            temp_cnt++;
        }else{
            cnt=max(cnt,temp_cnt);
            temp_cnt=0;
        }
    }
    cnt=max(cnt,temp_cnt);
    cout<<"Maximum Consecutive Ones are "<<cnt<<endl; 
    return 0;
}