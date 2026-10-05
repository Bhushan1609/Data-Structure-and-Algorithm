//Problem Link : https://leetcode.com/problems/maximum-subarray/description/

#include<bits/stdc++.h>
using namespace std;


void call_better(vector<int>&vec){
    int n=vec.size();
    next_permutation(vec.begin(),vec.end());                  // STL Implementation
}

void call_optimal(vector<int>&vec){
    int n=vec.size(),index=-1;
    for(int i=n-2;i>=0;i--){                                    // O(n)
        if(vec[i]<vec[i+1]){ 
            index=i;
            break;
        }
    }
    if(index==-1)
        reverse(vec.begin(),vec.end());
    else{
        for(int i=n-1;i>=index;i--){                            // O(n)
            if(vec[i]>vec[index]){
                swap(vec[i],vec[index]);
                break;
            }
        }
        reverse(vec.begin()+index+1,vec.end());                 // O(n)
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={3,1,2};

    // call_better(vec);
    // for(auto &num:vec)
    //     cout<<num<<" ";
    // cout<<endl;

    call_optimal(vec);
    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}