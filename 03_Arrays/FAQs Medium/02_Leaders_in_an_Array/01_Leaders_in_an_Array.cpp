//Problem-Link : https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

#include<bits/stdc++.h>
using namespace std;

void call_brute(vector<int>&vec){
    int n=vec.size();
    vector<int>ans;

    for(int i=0;i<n;i++){               // O(n*n)
        bool isLeader=true;
        for(int j=i+1;j<n;j++){
            if(vec[j]>vec[i])
                isLeader &= false;
        }
        if(isLeader)
            ans.push_back(vec[i]);
    }

    for(auto &num:ans)
        cout<<num<<" ";

    cout<<endl;
    return;
}

void call_optimal(vector<int>&vec){
    int n=vec.size();
    int maxi=vec[n-1];
    vector<int>ans;

    for(int i=n-1;i>=0;i--){                        // O(n)
        if(vec[i]>=maxi)
            ans.push_back(vec[i]);
        maxi=max(maxi,vec[i]);
    }

    reverse(ans.begin(),ans.end());

    for(auto &num:ans)
        cout<<num<<" ";

    cout<<endl;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={10,22,12,3,0,6};

    call_brute(vec);
    call_optimal(vec);

    return 0;
}