// Problem Link : https://www.geeksforgeeks.org/problems/shortest-job-first/1

#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id,profit,deadline;
};

bool comp(Job a,Job b){
    return a.profit>b.profit;
}

vector<int>jobSequencing(vector<int>&deadline,vector<int>&profit){
    int n=deadline.size();
    vector<Job>jobDesc(n);
    int maxDeadline=-1,tot_profit=0,cnt=0;

    for(int i=0;i<n;i++){
        jobDesc[i].id=i;
        jobDesc[i].profit=profit[i];
        jobDesc[i].deadline=deadline[i];
        maxDeadline=max(maxDeadline,deadline[i]);
    }

    vector<int>hash(maxDeadline+1,-1);

    sort(jobDesc.begin(),jobDesc.end(),comp);

    for(int i=0;i<n;i++){
        for(int j=jobDesc[i].deadline;j>0;j--){
            if(hash[j]==-1){
                tot_profit+=jobDesc[i].profit;
                cnt++;
                hash[j]=jobDesc[i].id;
                break;
            }
        }
    }

    return {cnt,tot_profit};
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>deadline={4,1,1,1},profit={40,10,40,30};

    vector<int>ans=jobSequencing(deadline,profit);
    cout<<"Number of jobs selected : "<<ans[0]<<"\nThe total maximum profit : "<<ans[1]<<endl;
    return 0;
}