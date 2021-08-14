#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll int dp[3001][3001];
ll int solve(vector<ll int> &v, int low, int high){
    if(low>high){
        return 0;
    }
    if(dp[low][high]!=-1){
        return dp[low][high];
    }
    ll int a=v[low]-solve(v,low+1,high);
    ll int b=v[high]-solve(v,low,high-1);
    return dp[low][high]=max(a,b);
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<ll int> v(n,0);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // cout<<v[0]<<endl;
    // double res=solve(v,0,0);
    ll int res=solve(v,0,n-1);
    cout<<res<<endl;
    return 0;
}