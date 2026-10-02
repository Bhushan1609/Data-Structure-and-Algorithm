//Problem Link : https://leetcode.com/problems/spiral-matrix/description/

#include<bits/stdc++.h>
using namespace std;

vector<int>spiral_mat(vector<vector<int>>&vec){
    int n=vec.size(),m=vec[0].size();
    int left=0,right=m-1,top=0,bottom=n-1;
    vector<int>ans;

    while(left<=right && top<=bottom){

        for(int j=left;j<=right;j++)
            ans.push_back(vec[top][j]);
        top++;

        for(int i=top;i<=bottom;i++)
            ans.push_back(vec[i][right]);
        right--;

        if(top<=bottom){
            for(int j=right;j>=left;j--)
                ans.push_back(vec[bottom][j]);

            bottom--;
        }

        if(left<=right){
            for(int i=bottom;i>=top;i--)
                ans.push_back(vec[i][left]);
            left++;
        }
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>>vec={{1,2,3,4,5,6},
                    {20,21,22,23,24,7},
                    {19,32,33,34,25,8},
                    {18,31,36,35,26,9},
                    {17,30,29,28,27,10},
                    {16,15,14,13,12,11}
    };

    for(auto &num: spiral_mat(vec))
        cout<<num<<" ";
    cout<<endl;
    return 0;
}