//Problem-Link : https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

#include<bits/stdc++.h>
using namespace std;

void call_optimal_anticlockwise(vector<int>&vec){
    vector<int>dummy=vec;                                       // don't tamper the give set of integer SC - O(n)
    int temp=dummy[0],n=dummy.size();

    for(int i=1;i<n;i++)                                        // TC - O(n)
        dummy[i-1]=dummy[i];
    dummy[n-1]=temp;

    for(auto &num:dummy)
        cout<<num<<" ";
    cout<<endl;
    return;
}

void call_optimal_clockwise(vector<int>&vec){
    vector<int>dummy=vec;                                       // don't tamper the give set of integer SC - O(n)
    int n=dummy.size();
    int temp=dummy[n-1];

    for(int i=n-2;i>=0;i--)                                        // TC - O(n)
        dummy[i+1]=dummy[i];
    dummy[0]=temp;

    for(auto &num:dummy)
        cout<<num<<" ";
    cout<<endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={1,2,3,4,5};

    call_optimal_anticlockwise(vec);
    call_optimal_clockwise(vec);
    return 0;
}