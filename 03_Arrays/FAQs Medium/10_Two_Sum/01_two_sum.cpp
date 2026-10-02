//Problem Link : https://leetcode.com/problems/two-sum/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> call_brute(vector<int>&vec,int target){
    int n=vec.size();
    vector<int>ans(2);
    for(int i=0;i<n;i++)                            // O(n*n)
        for(int j=0;j<n;j++)
            if(i!=j && vec[i]+vec[j]==target){
                ans[0]=i;
                ans[1]=j;
            }
    return ans;
}

vector<int> call_better(vector<int>&vec,int target){
    int n=vec.size();
    unordered_map<int,int>mapp;
    for(int i=0;i<n;i++){                        // O(n*log(n)) SC - O(n)
        int needSum=target-vec[i];
        if(mapp.find(needSum) != mapp.end())
            return {i,mapp[needSum]};
        mapp[vec[i]]=i;
    }
    return {0,0};
}

//If the array is sorted only need to reture YES or NO that target sum is present 
void call_optimal(vector<int>&vec,int target){
    int n=vec.size();
    sort(vec.begin(),vec.end());
    int start=0,end=n-1;
    while(start<end){
        if(vec[start]+vec[end]>target)
            end--;
        else if(vec[start]+vec[end]<target){
            start++;
        }else{
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={2,6,5,8,11};
    int target=14;

    for(auto &num:call_brute(vec,target))
        cout<<num<<" ";
    cout<<endl;
    for(auto &num:call_better(vec,target))
        cout<<num<<" ";
    cout<<endl;
    call_optimal(vec,target);
    return 0;
}
