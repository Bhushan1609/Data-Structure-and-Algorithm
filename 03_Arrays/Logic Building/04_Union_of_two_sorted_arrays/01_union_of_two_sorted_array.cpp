//Problem-Link : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include<bits/stdc++.h>
#include<set>
using namespace std;

void call_brute(vector<int>&vec1,vector<int>&vec2){
    int n=vec1.size();
    int m=vec2.size();
    vector<int>union_vec;               // SC - O(n+m)
    set<int>st;

    for(auto &num:vec1)                 // O(nlogn)
        st.insert(num);

    for(auto &num:vec2)                 // O(mlogm)
        st.insert(num);

    for(auto &num:st)                   // O(n+m)
        union_vec.push_back(num);

    for(auto &num:union_vec)           
        cout<<num<<" ";
    cout<<endl;
    return;
}

void call_optimal(vector<int>&vec1,vector<int>&vec2){
    int n=vec1.size(),m=vec2.size(),i=0,j=0;
    vector<int>union_vec;

    while(i<n && j<m){                                  // O(min(n,m))
        if(union_vec.empty()){
            if(vec1[i]<vec2[j])
                union_vec.push_back(vec1[i++]);
            else
                union_vec.push_back(vec2[j++]); 
        }else{
            if(vec1[i]<vec2[j]){
                if(union_vec.back()!=vec1[i])
                    union_vec.push_back(vec1[i]);
                i++;
            }else{
                if(union_vec.back()!=vec2[j])
                    union_vec.push_back(vec2[j]);
                j++;
            }
        }
    }

    while(i<n){                                         // O(n)
        if(union_vec.back()!=vec1[i])
            union_vec.push_back(vec1[i]);
        i++;
    }

    while(j<m){                                         // O(m)
        if(union_vec.back()!=vec2[j])
            union_vec.push_back(vec2[j]);
        j++;
    }

    for(auto &num:union_vec)           
        cout<<num<<" ";
    cout<<endl;
    return ;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec1={1,1,2,3,4,5};
    vector<int>vec2={2,3,4,4,5,6};

    call_brute(vec1,vec2);
    call_optimal(vec1,vec2);

    return 0;
}