//Problem Link : https://leetcode.com/problems/3sum/description/

#include<bits/stdc++.h>
#include<set>
using namespace std;

vector<vector<int>> call_brute(vector<int>&vec){
    int n=vec.size();
    set<vector<int>>st;                                                 // SC - O(n/3)

    for(int i=0;i<n;i++)                                                // O(n*n*n) + O(log(no of uniques triplets))
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(vec[i]+vec[j]+vec[k]==0){
                    vector<int>temp={vec[i],vec[j],vec[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }

    vector<vector<int>>ans(st.begin(),st.end());                        // SC - O(n/3)
    return ans;
}

vector<vector<int>> call_better(vector<int>&vec){
    int n=vec.size();
    set<vector<int>>ans_st;                                         // SC - O(n)

    for(int i=0;i<n;i++){                                           // O(n*n*log(n))
        set<int>st;
        for(int j=i+1;j<n;j++){
            int needElement=-(vec[i]+vec[j]);
            if(st.find(needElement)!=st.end()){
                vector<int>temp={vec[i],vec[j],needElement};
                    sort(temp.begin(),temp.end());
                    ans_st.insert(temp);
            }
            st.insert(vec[j]);
        }
    }
    vector<vector<int>>ans(ans_st.begin(),ans_st.end());        // SC - O(n)
    return ans;
}

vector<vector<int>> call_optimal(vector<int>&vec){
    int n=vec.size();
    vector<vector<int>>ans;                         // SC - O(no of triplets)

    sort(vec.begin(),vec.end());                   // O(nlogn)
    int i=0;
    for(int i=0;i<n;i++){                       // O(n*n)
        if(i>0 && vec[i-1]==vec[i])
            continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=vec[i]+vec[j]+vec[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                ans.push_back({vec[i],vec[j],vec[k]});
                j++;
                k--;
                while(j<k && vec[j]==vec[j-1])
                    j++;
                while(j<k && vec[k]==vec[k+1])
                    k--;
            }
        }
        
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={-1,0,1,2,-1,-4};

    for(auto &arr:call_brute(vec)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }   
    cout<<endl;
    for(auto &arr:call_better(vec)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }   
    cout<<endl;
    for(auto &arr:call_optimal(vec)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }   
    cout<<endl;
    return 0;
}
