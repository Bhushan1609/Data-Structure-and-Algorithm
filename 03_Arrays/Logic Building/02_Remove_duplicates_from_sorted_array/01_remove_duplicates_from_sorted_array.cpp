//Problem-Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include<bits/stdc++.h>
#include<set>
using namespace std;

void call_brute(vector<int>vec){
    int n=vec.size(),index=0;
    set<int>st;                         // SC - O(n)

    for(auto &num:vec)                  // TC - O(nlogn)
        st.insert(num);

    for(auto &num:st)                   // TC - O(n)
        vec[index++]=num;

    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return ;
}

void call_optimal(vector<int>vec){
    int n=vec.size();
    int i=0;
    for(int j=0;j<n;j++){            // TC - O(n)
        if(vec[j]!=vec[i]){
            vec[i+1]=vec[j];
            i++;
        }
    }

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
    
    vector<int>vec={1,1,2,2,2,3,3,};

    call_brute(vec);
    call_optimal(vec);
    return 0;
}