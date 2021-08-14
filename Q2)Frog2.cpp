#include<bits/stdc++.h>
using namespace std;
int dp[100002];
int solve(vector<int> &v, int index, int k){
    if(index==v.size()-1){
        //last index'
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int n=v.size();
    int res=INT_MAX;
    for(int i=1;i<=k;i++){
        if(index+i<n){
            int t=abs(v[index+i]-v[index])+solve(v,index+i,k);
            res=min(res,t);
        }
    }
    return dp[index]=res;
}
int main(){
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int res=solve(v,0,k);
    cout<<res<<endl;
    return 0;
}