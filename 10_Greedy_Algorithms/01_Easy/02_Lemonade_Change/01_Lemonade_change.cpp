// Problem Link : https://leetcode.com/problems/lemonade-change/description/

#include<bits/stdc++.h>
using namespace std;

int lemonadeChange(vector<int>&vec){
    int n=vec.size();
    int fives,tens;
    fives=tens=0;

    for(auto &num:vec){
        if(num==5)
            fives++;
        else if(num==10){
            if(!fives)
                return false;
            tens++,fives--;
        }else{
            if(tens && fives)
                tens--,fives--;
            else if(fives>=3)
                fives-=3;
            else
                return false;
        }
    }
    return true;
}
      
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<int>vec={5,5,5,10,20};

    if(lemonadeChange(vec))
        cout<<"Able to sell all lemonade"<<endl;
    else
        cout<<"Unable to sell all lemonade"<<endl;
    return 0;
}