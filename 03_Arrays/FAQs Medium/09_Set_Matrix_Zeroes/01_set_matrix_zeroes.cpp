//Problem Link : https://leetcode.com/problems/set-matrix-zeroes/description/

#include<bits/stdc++.h>
#include<set>
using namespace std;

void markRow(int i,vector<vector<int>>&vec){
    int m=vec[0].size();
    for(int j=0;j<m;j++)
        if(vec[i][j]!=0)
            vec[i][j]=-1;                               
}                                                                                                                                                                                                                      

void markCol(int j,vector<vector<int>>&vec){
    int n=vec.size();
    for(int i=0;i<n;i++)
        if(vec[i][j]!=0)
            vec[i][j]=-1;
}

/*
it get failed in leetcode soln because we're putting -1 
and the leetcode constraint are 
-2^31 <= matrix[i][j] <= 2^31 - 1 their are 
negatives present but brute soln works for binary matrix   
*/
void call_brute(vector<vector<int>>&vec){
    int n=vec.size(),m=vec[0].size();

    for(int i=0;i<n;i++)                                    // O(n*m*(n+m))
        for(int j=0;j<m;j++)
            if(vec[i][j]==0)
                markRow(i,vec),markCol(j,vec);

    for(auto &arr:vec)                                      // O(n*m)
        for(auto &num:arr)
            if(num==-1)
                num=0;

    for(auto &arr:vec){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }
    return ;
}

void call_better(vector<vector<int>>&vec){
    int n=vec.size(),m=vec[0].size();
    vector<int>row(n),col(m);                   // SC- O(n+m)

    for(int i=0;i<n;i++)                        // TC- O(n*m)
        for(int j=0;j<m;j++)
            if(vec[i][j]==0)
                row[i]++,col[j]++;

    for(int i=0;i<n;i++)                       // TC - O(n*m)
        for(int j=0;j<m;j++)
            if(row[i]|col[j])
                vec[i][j]=0;

    for(auto &arr:vec){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }
    return ;
}

void call_optimal(vector<vector<int>>&vec){
    int n=vec.size(),m=vec[0].size();
    int col0=1;

    for(int i=0;i<n;i++)                                        // O(n*m)
        for(int j=0;j<m;j++)
            if(vec[i][j]==0){
                if(j==0)
                    col0=0;
                else
                    vec[0][j]=0;
                vec[i][0]=0;
            }

    for(int i=1;i<n;i++)                                        // O(n*m)
        for(int j=1;j<m;j++)
           if(vec[i][j]!=0)
                if(vec[i][0]==0 or vec[0][j]==0)
                    vec[i][j]=0;

    if(vec[0][0]==0)
        for(int j=0;j<m;j++)
            vec[0][j]=0;   

    if(col0==0)
        for(int i=0;i<n;i++)
            vec[i][0]=0;

    for(auto &arr:vec){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }
    return ;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>vec={
        {1,1,1,1},
        {1,0,0,1},
        {1,1,0,1},
        {1,1,1,1}
    };

    // call_brute(vec);
    // call_better(vec);
    call_optimal(vec);
    return 0;
}
