#include<bits/stdc++.h>
using namespace std;
int dp[100002];
int solve(vector<int> &v, int index){
    if(index==v.size()-1){
        //last index'
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int n=v.size();
    //either i+1 or i+2
    int a=abs(v[index+1]-v[index])+solve(v,index+1);
    int b=INT_MAX;
    if(index+2<n){
        b=abs(v[index+2]-v[index])+solve(v,index+2);
    }
    return dp[index]=min(a,b);
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int res=solve(v,0);
    cout<<res<<endl;
    return 0;
}