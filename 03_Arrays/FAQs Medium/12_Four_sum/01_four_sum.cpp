//Problem Link : https://leetcode.com/problems/4sum/description/

#include<bits/stdc++.h>
#include<set>
using namespace std;

vector<vector<int>> call_brute(vector<int>&vec,int target){
    int n=vec.size();
    set<vector<int>>st;                                      // SC - O(no of triplets)

    for(int i=0;i<n;i++)                                    // O(n*n*n*n)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                for(int l=k+1;l<n;l++){
                    long long sum=vec[i];
                    sum+=vec[j];
                    sum+=vec[k];
                    sum+=vec[l];
                    if(sum==target){
                        vector<int>temp={vec[i],vec[j],vec[k],vec[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }

    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> call_better(vector<int>&vec,int target){
    int n=vec.size();
    set<vector<int>>ans_st;                                      // SC - O(no of triplets)

    for(int i=0;i<n;i++){                                    // O(n*n*n*log(n))
        for(int j=i+1;j<n;j++){
            set<long long>st;
            for(int k=j+1;k<n;k++){
                long long sum=vec[i];
                sum+=vec[j];
                sum+=vec[k];
                long long needSum=target-sum;
                if(st.find(needSum)!=st.end()){
                    vector<int>temp={vec[i],vec[j],vec[k],(int)needSum};
                    sort(temp.begin(),temp.end());
                    ans_st.insert(temp);
                }
                st.insert(vec[k]);
            }
        }
    }
    vector<vector<int>>ans(ans_st.begin(),ans_st.end());    
    return ans;
}

vector<vector<int>> call_optimal(vector<int>&vec,int target){
    int n=vec.size();
    vector<vector<int>>ans;
    sort(vec.begin(),vec.end());

    for(int i=0;i<n-3;i++){                                 // O(nearly abt n*n*n)
        if(i>0 && vec[i]==vec[i-1])
            continue;
        for(int j=i+1;j<n-2;j++){
            if(j!= i+1 && vec[j]==vec[j-1])
                continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=vec[i];
                sum+=vec[j];
                sum+=vec[k];
                sum+=vec[l];
                if(sum<target){
                    k++;
                }else if(sum>target){
                    l--;
                }else{
                    ans.push_back({vec[i],vec[j],vec[k],vec[l]});
                    k++;
                    l--;
                    while(k<l && vec[k]==vec[k-1])
                        k++;
                    while(k<l && vec[l]==vec[l+1])
                        l--;
                }
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

    vector<int>vec={0,0,0,0};
    int target=0;

    for(auto &arr:call_brute(vec,target)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }   
    cout<<endl;
    for(auto &arr:call_better(vec,target)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }   
    cout<<endl;
    for(auto &arr:call_optimal(vec,target)){
        for(auto &num:arr)
            cout<<num<<" ";
        cout<<endl;
    }   
    cout<<endl;
    return 0;
}
