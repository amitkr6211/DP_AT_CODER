#include<bits/stdc++.h>
using namespace std;
int dp[100002][4];

int solve(vector<vector<int>> &v, int index, int prev){
    if(index==v.size()){
        return 0;
    }
    if(dp[index][prev]!=-1){
        return dp[index][prev];
    }
    int res=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=prev){
            int t=v[index][i]+solve(v,index+1,i);
            res=max(res,t);
        }
    }
    return dp[index][prev]=res;
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<vector<int>> v(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    int res=solve(v,0,3);
    cout<<res<<endl;
    return 0;
}