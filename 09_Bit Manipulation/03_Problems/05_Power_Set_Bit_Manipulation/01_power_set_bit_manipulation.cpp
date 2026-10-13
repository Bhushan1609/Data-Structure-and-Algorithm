// Problem Link : https://leetcode.com/problems/subsets/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subSets(vector<int>&vec){
    int n=vec.size(),total_subsets=1<<n;
    vector<vector<int>>ans;

    for(int num=0;num<total_subsets;num++){             // O(2^n * n) SC - O(near abt 2^n * n)
        vector<int>temp;
        for(int i=0;i<n;i++){       
            if((num & (1<<i)) != 0)
                temp.push_back(vec[i]);
        }
        ans.emplace_back(temp);
    }

    return ans;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,2,3};
    for(auto &arr:subSets(vec)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }

    return 0;
}