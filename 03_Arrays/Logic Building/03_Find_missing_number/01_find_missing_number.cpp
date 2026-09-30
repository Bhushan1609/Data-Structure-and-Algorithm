//Problem-Link : https://leetcode.com/problems/missing-number/description/

#include<bits/stdc++.h>
#include<set>
using namespace std;

void call_brute(vector<int>vec){
    int n=vec.size();
    int missing_num;
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=0;j<n;j++){
            if(vec[j]==i)
                flag |= true;
        }
        if(!flag){
            missing_num=i;
            break;
        }
    }
    cout<<"Missing number is "<<missing_num<<endl;
    return;
}

void call_better(vector<int>vec){
    int n=vec.size(),missing_num;
    vector<int>hash(n+1,0);

    for(int i=0;i<n;i++)
        ++hash[vec[i]];
    
    for(int i=0;i<n+1;i++)
        if(hash[i]==0)
            missing_num=i;

    cout<<"Missing number is "<<missing_num<<endl;
    return;   
}

void call_optimal(vector<int>vec){
    int n=vec.size();
    int sum=(n)*(n+1);
    sum>>=1;

    for(int i=0;i<n;i++)
        sum-=vec[i];

    cout<<"Missing number is "<<sum<<endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={9,6,4,2,3,5,7,0,1};

    call_brute(vec);
    call_better(vec);
    call_optimal(vec);
    return 0;
}