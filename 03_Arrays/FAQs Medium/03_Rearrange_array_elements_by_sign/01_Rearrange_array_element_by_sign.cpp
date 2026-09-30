//Problem-Link : https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

#include<bits/stdc++.h>
using namespace std;

void call_brute(vector<int>&vec){
    int n=vec.size();
    vector<int>neg,pos,ans;

    for(auto &num:vec){                                     // O(N)
        if(num<0)
            neg.push_back(num);
        else 
            pos.push_back(num);
    }

    int size1=neg.size(),size2=pos.size();

    for(int i=0;i<min(size1,size2);i++){                    // both for loops takes O(n) 
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }

    for(int i=min(size1,size2);i<max(size1,size2);i++){     
        if(i<size1)
            ans.push_back(neg[i]);

        if(i<size2)
            ans.push_back(pos[i]);
    }

    for(auto &num:ans)
        cout<<num<<" ";

    cout<<endl;
    return;
}

void call_optimal(vector<int>&vec){
    int n=vec.size();
    vector<int>ans(n);
    int posIndex=0,negIndex=1;

    for(auto &num:vec){                                 // O(n)
        if(num<0){
            ans[negIndex]=num;
            negIndex+=2;
        }
        else{
            ans[posIndex]=num;
            posIndex+=2;
        }
    }

    for(auto &num:ans)
        cout<<num<<" ";

    cout<<endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={3,1,-2,-5,2,-4};

    call_brute(vec);
    call_optimal(vec);

    return 0;
}