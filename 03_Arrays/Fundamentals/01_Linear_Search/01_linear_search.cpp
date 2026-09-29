//Problem-Link : https://www.naukri.com/code360/problems/linear-search_2109212

#include<bits/stdc++.h>
using namespace std;

void linear_search(int num,vector<int>&vec){
    int n=vec.size();
    for(int i=0;i<vec.size();i++){                                      //O(N)
        if(vec[i]==num){
            cout<<"Found "<<num<<" at index : "<<i<<endl;
            return ;
        }
    }
    cout<<num<<" is not present."<<endl;
    return ;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={6,7,8,4,1};
    int num=4;

    linear_search(num,vec);
    return 0;
}