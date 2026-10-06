//Problem Link : https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

#include<bits/stdc++.h>
using namespace std;

void call_brute(vector<int>&vec1,vector<int>&vec2){
    int n=vec1.size(),m=vec2.size();
    vector<int>vec3(n+m,0);                         // SC - O(n+m)
    int index=0;
    int i=0,j=0;
    while(i<n && j<m){                              // O(n+m)
        if(vec1[i]<vec2[j]){
            vec3[index++]=vec1[i++];
        }else{
            vec3[index++]=vec2[j++];
        }
    }
    while(i<n)
        vec3[index++]=vec1[i++];

    while(j<m)
        vec3[index++]=vec2[j++];

    for(int i=0;i<n+m;i++){                             // O(n+m)
        if(i<n) 
            vec1[i]=vec3[i];
        else
            vec2[i-n]=vec3[i];
    }
    return ;
}

void call_optimal1(vector<int>&vec1,vector<int>&vec2){
    int n=vec1.size(),m=vec2.size();
    int left=n-1,right=0;
    while(left>=0 && right<m){                      // O(min(n,m))
        if(vec1[left]>vec2[right]){
            swap(vec1[left--],vec2[right++]);
        }else{
            break;
        }
    }
    sort(vec1.begin(),vec1.end());                  // O(nlogn)
    sort(vec2.begin(),vec2.end());                  // O(mlogm)
    return ;                                        // O(nlogn) + O(mlogm) + O(min(n,m))
}

void swapIfGreater(vector<int>&vec1,vector<int>&vec2,int ind1,int ind2){
    if(vec1[ind1]>vec2[ind2]){
        swap(vec1[ind1],vec2[ind2]);
    }
}

void call_optimal2(vector<int>&vec1,vector<int>&vec2){
    int n=vec1.size(),m=vec2.size();
    int len=(n+m);
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            // vec1 & vec2
            if(left<n && right>=n){
                swapIfGreater(vec1,vec2,left,right-n);
            }//vec2 & vec2
            else if(left>=n){
                swapIfGreater(vec2,vec2,left-n,right-n);
            }//vec1 & vec1
            else{
                swapIfGreater(vec1,vec1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1)break;
        gap=(gap/2)+(gap%2);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec1={1,3,5,7},vec2={0,2,6,8,9};
    //call_brute(vec1,vec2);
    // call_optimal1(vec1,vec2);
    call_optimal2(vec1,vec2);

    for(auto &num:vec1)
        cout<<num<<" ";
    cout<<endl;

    for(auto &num:vec2)
        cout<<num<<" ";
    cout<<endl;

    
    return 0;
}