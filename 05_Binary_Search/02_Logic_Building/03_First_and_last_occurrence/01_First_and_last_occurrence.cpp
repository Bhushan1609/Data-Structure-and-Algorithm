#include<bits/stdc++.h>
using namespace std;

pair<int,int>occurence(int target,vector<int>&vec){
    int lb=lower_bound(vec.begin(),vec.end(),target)-vec.begin();
    int ub=upper_bound(vec.begin(),vec.end(),target)-vec.begin();

    if(lb==vec.size() || vec[lb]!=target)
        return {-1,-1};
    return {lb,ub-1};
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={2,4,6,8,8,8,11,13};
    int target=8;

    pair<int,int>ans=occurence(target,vec);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}