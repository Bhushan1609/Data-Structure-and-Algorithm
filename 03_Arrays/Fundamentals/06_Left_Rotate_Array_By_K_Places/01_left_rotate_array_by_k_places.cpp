#include<bits/stdc++.h>
using namespace std;

//Problem-Link : https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1
// Clockwise Rotation (left shift)
void call_brute_c(vector<int>vec,int d){
    int n=vec.size();
    d%=n;
    if(d==0)
        return;
    vector<int>temp;

    for(int i=d;i<n;i++)                   // O(n-d)
        temp.push_back(vec[i]);

    for(int i=0;i<d;i++)                   // O(d)
        temp.push_back(vec[i]);

    vec=temp;                              // O(n)
                                           // Extra space taken by the temp array SC - O(n)
    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return ;
}

void call_optimal_c(vector<int>vec,int d){
    int n=vec.size();
    d%=n;
    if(d==0)
        return;
    reverse(vec.begin(),vec.begin()+d);     // O(d)
    reverse(vec.begin()+d,vec.end());       // O(n-d)
    reverse(vec.begin(),vec.end());         // O(n)

    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
}

//Problem-Link : https://leetcode.com/problems/rotate-array/
// Anti-Clockwise Rotation (right shift)
void call_brute_ac(vector<int>vec,int d){
    int n=vec.size();
    d=d%n;
    if(d==0)
        return;
    vector<int>temp;

    for(int i=n-d;i<n;i++)                  // O(d)
        temp.push_back(vec[i]);
    
    for(int i=0;i<n-d;i++)                  // O(n-d)
        temp.push_back(vec[i]);

    vec=temp;                               // O(n) 
                                            // Extra space taken by the temp array SC - O(n)
    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
    return ;
}

void call_optimal_ac(vector<int>vec,int d){
    int n=vec.size();
    d%=n;
    if(d==0)
        return;
    reverse(vec.begin()+n-d,vec.end());     // O(d)
    reverse(vec.begin(),vec.begin()+n-d);   // O(n-d)
    reverse(vec.begin(),vec.end());         // O(n)

    for(auto &num:vec)
        cout<<num<<" ";
    cout<<endl;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec={1,2,3,4,5,6,7};
    int d=3;

    call_brute_c(vec,d);
    call_optimal_c(vec,d);

    call_brute_ac(vec,d);
    call_optimal_ac(vec,d);
    return 0;
}