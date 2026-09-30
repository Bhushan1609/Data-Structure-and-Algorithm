//Problem-Link : https://leetcode.com/problems/move-zeroes/

#include<bits/stdc++.h>
using namespace std;

void call_brute(vector<int>vec){
    int n=vec.size();
    vector<int>temp;
    for(auto &num:vec)                // O(n)    
        if(num)
            temp.push_back(num);
    for(int i=0;i<n;i++){             // O(n)
        if(i<temp.size())
            vec[i]=temp[i];
        else
            vec[i]=0;
    }

    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return ;
}

void call_optimal(vector<int>vec){  
    int n=vec.size();
    int i=0,j=0;

    while(j<n && vec[j]!=0)                 // O (till the first occurence of zero)
        j++;
    i=j+1;
    while(i<n){                             // O(till the first occurence of zero +1 to n)
        if(vec[i]!=0){
            swap(vec[i],vec[j]);
            j++;
        }
        i++;
    }                                       // total O(n)
    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return ;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={1,0,2,3,2,0,0,4,5,1};

    call_brute(vec);
    call_optimal(vec);
    return 0;
}