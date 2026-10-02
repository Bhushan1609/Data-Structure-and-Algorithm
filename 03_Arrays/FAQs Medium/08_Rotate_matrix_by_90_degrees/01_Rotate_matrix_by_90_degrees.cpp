//Problem Link : https://leetcode.com/problems/rotate-image/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> call_brute(vector<vector<int>>&vec){
    int n=vec.size(),m=vec[0].size();
    vector<vector<int>>ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++)                                                // O(n*m)
        for(int j=0;j<m;j++)
            ans[j][n-1-i]=vec[i][j];
    return ans;
}

vector<vector<int>> call_optimal(vector<vector<int>>&vec){
    int n=vec.size(),m=vec[0].size();
    for(int i=0;i<n;i++)                                                    // O(n/2*m/2)
        for(int j=i+1;j<m;j++)
            swap(vec[i][j],vec[j][i]);

    for(int i=0;i<n;i++){                                                   // O(n*m/2)
        int start=0,end=m-1;
        while(start<=end)
            swap(vec[i][start++],vec[i][end--]);
    }
    return vec;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>vec={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    for(auto &arr:call_brute(vec)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(auto &arr:call_optimal(vec)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}
