//Problem Link : https://leetcode.com/problems/longest-consecutive-sequence/

#include<bits/stdc++.h>
using namespace std;

bool checkNext(int num,int &len,vector<int>&vec){
    int n=vec.size();
    for(int i=0;i<n;i++){
        if(num==vec[i]){
            len++;
            return true;
        }
    }
    return false;
}

int call_brute(vector<int>&vec){
    int n=vec.size(),max_len=0;

    for(int i=0;i<n;i++){                           // O(n*n)
        int num=vec[i]+1;
        int len=1;
        while(checkNext(num,len,vec))
            num++;
        max_len=max(max_len,len);
    }
    return max_len;
}

int call_better(vector<int>&vec){
    int n=vec.size();
    sort(vec.begin(),vec.end());            // O(nlogn)
    int max_len=0,cnt=0,last;

    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            last=vec[i];
        }else if(vec[i]==last+1){
            cnt++;
            last=vec[i];
        }else{
            if(vec[i]==last)
                continue;
            max_len=max(max_len,cnt);
            cnt=1;
            last=vec[i];
        }
    }
    max_len=max(max_len,cnt);
    return max_len;
}

int call_optimal(vector<int>&vec){
    int n=vec.size(),max_len=0;
    unordered_set<int>st;

    for(auto &num:vec)                          // O(n)
        st.insert(num);

    for(auto &num:st){                          // O(2n)
        if(st.find(num-1)==st.end()){
            int cnt=1;
            int number=num;
            while(st.find(number+1)!=st.end())
                cnt++,number++;
            max_len=max(max_len,cnt);
        }  
    }
    return max_len;                                     // TC - O(3n)  SC - O(n)
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={102,4,100,1,101,3,2,1,1};
    cout<<call_brute(vec)<<endl;
    // cout<<call_better(vec)<<endl;
    cout<<call_optimal(vec)<<endl;

    return 0;
}