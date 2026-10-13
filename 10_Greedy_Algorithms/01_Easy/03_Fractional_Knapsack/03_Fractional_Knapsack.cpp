// Problem Link : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>&a,vector<int>&b){
    double val1=a[0]*1.0,val2=b[0]*1.0;
    double wt1=a[1]*1.0,wt2=b[1]*1.0;
    double com1=val1/wt1,com2=val2/wt2;
    return com1>com2;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n=val.size();
    double ans=0.0;
    vector<vector<int>>vec;

    for(int i=0;i<n;i++)
        vec.push_back({val[i],wt[i]});

    sort(vec.begin(),vec.end(),compare);        //O(nlogn)

    int it=0;
    while(capacity && it<vec.size()){                   // O(n)
        if(vec[it][1]>capacity){
            ans += (1.0*vec[it][0]/vec[it][1])*capacity;
            break;
        }else{
            ans+=vec[it][0];
            capacity-=vec[it][1];
        }
        it++;
    }
    return ans;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>val={60,100,120},wt={10,20,30};
    int capacity=50;

    cout<<(double)fractionalKnapsack(val,wt,capacity);
    return 0;
}