//Problem Link : https://leetcode.com/problems/majority-element-ii/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> call_brute(vector<int>&vec){
    int n=vec.size();
    vector<int>ans;
    for(int i=0;i<n;i++){                                   // O(n*n)
        if(ans.size()>0 && ans[0]==vec[i])
            continue;
        int cnt=0;
        for(int j=0;j<n;j++)
            cnt+=(vec[i]==vec[j]);
        if(cnt>n/3)
            ans.push_back(vec[i]);
        if(ans.size()==2)
            break;
    }
    return ans;
}

vector<int> call_better(vector<int>&vec){
    int n=vec.size();
    vector<int>ans;
    unordered_map<int,int>mapp;                  // SC - O(n)
    for(auto &num:vec){                         // O(nlogn)
        mapp[num]++;
        if(mapp[num]*3>n){
            if(ans.size()>0){
                if(ans.back()!=num)
                    ans.push_back(num);
            }
            else{
                ans.push_back(num);
            }
        }
        if(ans.size()==2)
            break;
    }
    return ans;
}

vector<int> call_optimal(vector<int>&vec){
    int n=vec.size();
    vector<int>ans;
    int ele1,cnt1,ele2,cnt2;
    cnt1=cnt2=0;
    ele1=ele2=-1e9-1;
    for(int i=0;i<n;i++){                                   // O(n)
        if(cnt1==0 && vec[i]!=ele2){
            cnt1=1;
            ele1=vec[i];
        }else if(cnt2==0 && vec[i]!=ele1){
            cnt2=1;
            ele2=vec[i];
        }else if(ele1==vec[i]){
            cnt1++;
        }else if(ele2==vec[i]){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=cnt2=0;
    for(int i=0;i<n;i++){                               // O(n)
        cnt1+=(ele1==vec[i]);
        cnt2+=(ele2==vec[i]);
    }
    if(cnt1*3>n)
        ans.push_back(ele1);
    if(cnt2*3>n)
        ans.push_back(ele2);
    return ans;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={1,1,1,3,3,2,2,2};

    for(auto &num:call_brute(vec))
        cout<<num<<" ";
    cout<<endl;

    for(auto &num:call_better(vec))
        cout<<num<<" ";
    cout<<endl;

    for(auto &num:call_optimal(vec))
        cout<<num<<" ";
    cout<<endl;
    return 0;
}