//Problem Link : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include<bits/stdc++.h>
using namespace std;

vector<int> call_brute(vector<int>&vec){
    int n=vec.size();
    int repeating=-1,missing=-1;

    for(int i=1;i<=n;i++){                  // O(n*n)
        int cnt=0;
        for(int j=0;j<n;j++)
            cnt+=(vec[j]==i);
        if(cnt==0)
            missing=i;
        else if(cnt==2)
            repeating=i;
        if(repeating!=-1 && missing!=-1)
            break;
    }
    return {repeating,missing};
}

vector<int> call_better(vector<int>&vec){
    int n=vec.size();
    int repeating=-1,missing=-1;
    vector<int>hash(n+1,0);             // SC - O(n)

    for(auto &num:vec)                  // O(n)
        hash[num]++;

    for(int i=1;i<=n;i++){              // O(n)
        if(hash[i]==0)
            missing=i;
        else if(hash[i]==2)
            repeating=i;
        if(repeating!=-1 && missing!=-1)
            break;
    }
    return {repeating,missing};
}

vector<int> call_optimal1(vector<int>&vec){
    long long n=vec.size();
    long long sum_arr=0,sum_n=n*(n+1);
    sum_n>>=1;

    long long sum_of_square_arr=0,sum_of_square_n=n*(n+1)*(2*n+1);
    sum_of_square_n/=6;

    for(auto &num:vec){                                             // O(n)
        sum_arr+=num;
        sum_of_square_arr+=(long long)num*(long long)num;
    }

    long long sum_diff=sum_arr-sum_n;
    long long square_diff=sum_of_square_arr-sum_of_square_n;
    square_diff/=sum_diff;
    square_diff+=sum_diff;
    square_diff>>=1;
    return {int(square_diff),int(square_diff-sum_diff)};
}

vector<int> call_optimal2(vector<int>&vec){
    int n=vec.size();
    int number=0;
    for(int i=0;i<n;i++){                       // O(n)
        number^=i+1;
        number^=vec[i];
    }
    int bitNo=0;
    while(1){                                       // O(32)
        if((number & (1<<bitNo)) != 0){
            break;
        }else{
            bitNo++;
        }
    }
    int zerobit=0,onebit=0;
    for(int i=0;i<n;i++){                               // O(n)                         
        if((vec[i] & (1<<bitNo)) != 0){
            onebit^=vec[i];
        }else{
            zerobit^=vec[i];
        }
    }
    for(int i=1;i<=n;i++){
        if((i & (1<<bitNo))!=0){
            onebit^=i;
        }else{
            zerobit^=i;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)                            // O(n)
        cnt+=(zerobit==vec[i]);
    if(cnt==2)
        return {zerobit,onebit};
    return {onebit,zerobit};
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={4,3,6,2,1,1};

    for(auto &num:call_brute(vec))
        cout<<num<<" ";
    cout<<endl;

    for(auto &num:call_better(vec))
        cout<<num<<" ";
    cout<<endl;

    for(auto &num:call_optimal1(vec))
        cout<<num<<" ";
    cout<<endl;

    for(auto &num:call_optimal2(vec))
        cout<<num<<" ";
    cout<<endl;
    return 0;
}