// Problem Link : https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<bits/stdc++.h>
using namespace std;

int minPlatform(vector<int>&arrival,vector<int>&departure){
    int n=arrival.size();
    int maxCnt=0;
    int i=0,j=0,cnt=0;

    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());

    while(i<n){
        if(arrival[i]<=departure[j]){
            i++;
            cnt++;
        }else{
            j++;
            cnt--;
        }
        maxCnt=max(maxCnt,cnt);
    }
    return maxCnt;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>arrival={900,945,955,1100,1500,1800},departure={920,1200,1130,1150,1900,200};
    
    cout<<minPlatform(arrival,departure)<<endl;
    return 0;
}