//Problem Link : https://leetcode.com/problems/sort-colors/description/

#include<bits/stdc++.h>
using namespace std;

void call_brute(vector<int>vec){
    int n=vec.size();
    sort(vec.begin(),vec.end());            // O(n*logn)
    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return;
}

void call_better(vector<int>vec){
    int n=vec.size();
    int cnt0=0,cnt1=0,cnt2=0;
    for(auto &num:vec){                         // O(n)
        cnt0+=(num==0);
        cnt1+=(num==1);
        cnt2+=(num==2);
    }
    for(auto &num:vec){                         // O(n)
        if(cnt0>0){
            num=0;
            cnt0--;
        }else if(cnt1>0){
            num=1;
            cnt1--;
        }else{
            num=2;
        }
    }

    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return;
}

void call_optimal(vector<int>vec){
    int n=vec.size();
    int low,mid,high;
    low=mid=0;
    high=n-1;
    while(mid<=high){                               // O(n)
        if(vec[mid]==0){
            swap(vec[low++],vec[mid++]);
        }else if(vec[mid]==1){
            mid++;
        }else{
            swap(vec[mid],vec[high]);
            high--;
        }
    }
    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={0,1,2,0,1,2,1,2,0,0,0,1};

    call_brute(vec);
    call_better(vec);
    call_optimal(vec);
    return 0;
}
