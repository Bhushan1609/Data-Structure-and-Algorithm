//Problem-Link : https://www.naukri.com/code360/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

#include<bits/stdc++.h>
using namespace std;

void call_brute(vector<int>&vec){
    int n=vec.size();
    vector<int>dummy=vec;                                       // don't tamper the given vector
    sort(dummy.begin(),dummy.end(),greater<>());                // O(nlogn)
    cout<<"Largest element in an array is "<<dummy[0]<<endl;
    return;
}

void call_optimal(vector<int>&vec){
    int n=vec.size();
    int largest=vec[0];
    for(int i=1;i<n;i++){                                       // O(n)
        if(vec[i]>largest)
            largest=vec[i];
    }
    cout<<"Largest element in an array is "<<largest<<endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={3,2,1,5,2};

    call_brute(vec);
    call_optimal(vec);
    return 0;
}