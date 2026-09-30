//Problem-Link : https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149

#include<bits/stdc++.h>
using namespace std;

void call_brute(vector<int>&vec){
    int n=vec.size(),element=-1;

    for(int i=0;i<n;i++){              // O(n*n)
        int cnt=0;
        for(int j=0;j<n;j++)
            cnt+=(vec[i]==vec[j]);
        if(cnt>(n>>1))
            element=vec[i];
    }
    cout<<"Majority Element is "<<element<<endl;
    return;
}

void call_better(vector<int>&vec){                  // O(nlogn)
    int n=vec.size(),element=-1;
    unordered_map<int,int>mapp;
    for(auto &num:vec)
        ++mapp[num];
    for(auto &[i,j]:mapp)
        if(j>(n>>1))
            element=i;

    cout<<"Majority Element is "<<element<<endl;
    return;
}

void call_optimal(vector<int>&vec){
    int n=vec.size(),element=-1,cnt=0;

    for(int i=0;i<n;i++){                   // O(n)
        if(cnt==0){
            cnt++;
            element=vec[i];
        }else if(element==vec[i]){
            cnt++;
        }else{
            cnt--;
        }
    }

    cout<<"Majority Element is "<<element<<endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={2,2,3,3,1,2,2};

    call_brute(vec);
    call_better(vec);
    call_optimal(vec);

    return 0;
}