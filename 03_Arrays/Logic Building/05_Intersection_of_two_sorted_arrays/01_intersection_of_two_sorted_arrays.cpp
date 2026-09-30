//Problem-Link : https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149

#include<bits/stdc++.h>
#include<set>
using namespace std;

void call_brute(vector<int>&vec1,vector<int>&vec2){
    int n=vec1.size(),m=vec2.size();
    vector<int>common_vec,vis(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){                           // O(n*m)
            if(vec1[i]==vec2[j] && !vis[j]){
                common_vec.push_back(vec1[i]);
                ++vis[j];
                break;
            }
        }
    }

    for(auto &num:common_vec)
        cout<<num<<" ";
    cout<<endl;
    return ;
}

void call_optimal(vector<int>&vec1,vector<int>&vec2){
    int n=vec1.size(),m=vec2.size(),i=0,j=0;
    vector<int>common_vec;

    while(i<n && j<m){                                      // O(min(n,m)) 
        if(vec1[i]==vec2[j]){
            common_vec.push_back(vec1[i]);
            i++,j++;
        }else if(vec1[i]<vec2[j]){
            i++;
        }else{
            j++;
        }
    }

    for(auto &num:common_vec)
        cout<<num<<" ";
    cout<<endl;
    return ;
}

int main(){
    #ifndef ONLINE_JUDEG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>vec1={1,2,2,3,3,4,5,6};
    vector<int>vec2={2,3,3,5,6,6,7};

    call_brute(vec1,vec2);
    call_optimal(vec1,vec2);

    return 0;
}