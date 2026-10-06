//Problem Link : https://leetcode.com/problems/reverse-pairs/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec){
    int n=vec.size();
    int cnt=0;
    for(int i=0;i<n;i++){                                       // O(n*n)
        for(int j=i+1;j<n;j++)
            cnt+=(vec[i]>2*1LL*vec[j]);
    }
    return cnt;
}

void merge(int low,int mid,int high,vector<int>&vec){
    int left=low;
    int right=mid+1;
    vector<int>temp;

    while(left<=mid && right<=high){
        if(vec[left]<=vec[right]){
            temp.push_back(vec[left]);
            left++;
        }else{
            temp.push_back(vec[right]);
            right++;
        }
    }

    while(left<=mid)
        temp.push_back(vec[left++]);

    while(right<=high)
        temp.push_back(vec[right++]);

    for(int i=low;i<=high;i++)
        vec[i]=temp[i-low];

    return;
}

int countPairs(int low,int mid,int high,vector<int>&vec){
    int cnt=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && vec[i]>2*1LL*vec[right])
            right++;
        cnt+=(right-(mid+1));
    }
    return cnt;
}

int divide(int low,int high,vector<int>&vec){
    int cnt=0;
    if(low>=high)
        return cnt;
    int mid=(low+high)>>1;
    cnt+=divide(low,mid,vec);
    cnt+=divide(mid+1,high,vec);
    cnt+=countPairs(low,mid,high,vec);
    merge(low,mid,high,vec);
    return cnt;
}

int merge_sort(vector<int>&vec){
    int n=vec.size();
    return divide(0,n-1,vec);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={40,25,19,12,9,6,2};
    cout<<call_brute(vec)<<endl;
    cout<<merge_sort(vec)<<endl;                // O(2nlogn) SC - O(n)
    return 0;
}