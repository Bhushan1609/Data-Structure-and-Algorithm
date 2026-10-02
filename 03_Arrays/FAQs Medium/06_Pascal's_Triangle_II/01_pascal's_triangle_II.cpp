//Problem Link : https://leetcode.com/problems/pascals-triangle/description/
//               https://leetcode.com/problems/pascals-triangle-ii/description/

#include<bits/stdc++.h>
using namespace std;

/*
Pascal Triangle
     1 2 3 4 5 6 7
1    1                   
2    1 1                 
3    1 2 1               
4    1 3 3 1             
5    1 4 6 4 1           
6    1 5 10 10 5 1      
*/

// Print the value of some row and some col from pascal triangle
int nCr(int n,int r){
    long long res=1;

    for(int i=0;i<r;i++)                 // O(r)
        res *= (n-i),res /= (i+1);

    return res;
}

// Print the nth row of the pascal triangle
vector<int> printRow(int n){
    vector<int>vec;
    for(int col=1;col<=n;col++)                 // O(n*n)
        vec.push_back(nCr(n-1,col-1));
    return vec;
}

vector<int> printRow_Optimal(int n){
    vector<int>vec;
    long long ans=1;
    vec.push_back(ans);
    for(int col=1;col<n;col++){                // O(n)
        ans*=(n-col),ans/=col;
        vec.push_back(ans);
    }
    return vec;
}

vector<vector<int>>print_pascal_triangle_brute(int n){
    vector<vector<int>>ans;
    for(int row=1;row<=n;row++){                                // nearly about O(n*n*n)
        vector<int>temp;
        for(int col=1;col<=row;col++)
            temp.push_back(nCr(row-1,col-1));
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int>>print_pascal_triangle_optimal(int n){
    vector<vector<int>>ans;

    for(int row=1;row<=n;row++)                               // O(n*n)
        ans.push_back(printRow_Optimal(row));
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int row=5,col=3,n=5;

    cout<<"Value of nCr is "<<nCr(row-1,col-1)<<endl; 

    for(auto &num :printRow(n))
        cout<<num<<" ";
    cout<<endl;
    
    for(auto &num :printRow_Optimal(n))
        cout<<num<<" ";
    cout<<endl;

    for(auto &vec:pascal_triangle_brute(n)){
        for(auto &num:vec)
            cout<<num<<" ";
        cout<<endl;
    }

    for(auto &vec:pascal_triangle_optimal(n)){
        for(auto &num:vec)
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}
