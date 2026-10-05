//Problem Link : https://leetcode.com/problems/maximum-subarray/description/

#include<bits/stdc++.h>
using namespace std;

int call_brute(vector<int>&vec){
    int n=vec.size(),max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){                           // O(n*n*n)
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=vec[k];
            }
            max_sum=max(max_sum,sum);
        }
    }
    return max_sum;
}

int call_better(vector<int>&vec){
    int n=vec.size(),max_sum=INT_MIN;
    for(int i=0;i<n;i++){                               // O(n*n)
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=vec[j];
            max_sum=max(max_sum,sum);
        }
    }
    return max_sum;
}

int call_optimal(vector<int>&vec){
    int n=vec.size(),max_sum=INT_MIN,sum=0;
    int ansstart,ansend,start;
    for(int i=0;i<n;i++){                                       // O(n)
        if(sum==0)
            start=i;

        sum+=vec[i];

        if(sum>max_sum){
            max_sum=sum;
            ansstart=start;
            ansend=i;
        }
        if(sum<0)
            sum=0;
    }

    // Printing the subarray with maximum sum
    // for(int i=ansstart;i<=ansend;i++)
    //     cout<<vec[i]<<" ";
    // cout<<endl;
    return max_sum;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={-2,-3,4,-1,-2,1,5,-3};

    cout<<call_brute(vec)<<endl;
    cout<<call_better(vec)<<endl;
    cout<<call_optimal(vec)<<endl;
    return 0;
}