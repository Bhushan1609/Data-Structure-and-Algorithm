// Problem Link : https://www.geeksforgeeks.org/problems/shortest-job-first/1

#include<bits/stdc++.h>
using namespace std;

int SJF(vector<int>&vec){                   
    int n=vec.size();
    int time=0,ans=0;
    sort(vec.begin(),vec.end()); // O(nlogn) + O(n)
    for(auto &num:vec){
        ans+=time;
        time+=num;
    }
    return ans/n;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={4,3,7,1,2};
    cout<<SJF(vec)<<endl;
    return 0;
}