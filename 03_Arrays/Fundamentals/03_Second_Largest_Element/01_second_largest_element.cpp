//Problem-Link : https://www.geeksforgeeks.org/problems/second-largest3735/1

#include<bits/stdc++.h>
using namespace std;

void call_brute(vector<int>&vec){
    int n=vec.size();
    vector<int>dummy=vec;                                       // don't tamper the given vector 
    sort(dummy.begin(),dummy.end(),greater<>());                // O(nlogn)
    int largest=dummy[0];
    int iterator=1;

    while(iterator<n && dummy[iterator]==largest)               // O(n)
        iterator++;
    int ans;
    if(iterator==n)
        ans=-1;
    else
        ans=dummy[iterator];

    cout<<"The second largest element in vector is "<<ans<<endl;
    return;
}

void call_better(vector<int>&vec){
    int n=vec.size();
    int largest=vec[0];
    int second_largest=-1;
    for(int i=0;i<n;i++){                                           // O(n)
        if(vec[i]>largest)
            largest=vec[i];
    }

    for(int i=0;i<n;i++){                                          // O(n)
        if(vec[i]>second_largest && vec[i]!=largest)
            second_largest=vec[i];
    }

    cout<<"The second largest element in vector is "<<second_largest<<endl;
    return;
}

void call_optimal(vector<int>&vec){
    int n=vec.size();
    int largest=vec[0];
    int second_largest=-1;

    for(int i=1;i<n;i++){                                       // O(n)
        if(vec[i]>largest){
            second_largest=largest;
            largest=vec[i];
        }else if(vec[i]>second_largest && largest != vec[i]) 
            second_largest=vec[i];
    }
    cout<<"The second largest element in vector is "<<second_largest<<endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={1,2,4,7,7,5};

    call_brute(vec);
    call_better(vec);
    call_optimal(vec);
    return 0;
}