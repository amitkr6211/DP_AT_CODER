#include<bits/stdc++.h>
using namespace std;
#define ll long long
// static ll int mod= 10e9+7;
#define mod 1000000007
ll int dp[401][401];
ll int solve(vector<ll int> & v,vector<ll int> & prefix, ll int low, ll int high){
    if(low==high){
        return 0;
    }
    if(low>high){
        return 0;
    }
    if(dp[low][high]!=-1){
        return dp[low][high];
    }
    ll int cost=prefix[high];
    if(low-1>=0){
        cost-=prefix[low-1];
    }
    ll int res=LLONG_MAX;
    for(int i=low;i<high;i++){
        
        ll int t=cost+solve(v,prefix,low,i)+solve(v,prefix,i+1,high);
        
        res=min(res,t);
    }
    return dp[low][high]=res;
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    vector<ll int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll int> prefix(n,0);
    prefix[0]=v[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+v[i];
    }
    // ll int res=solve(v,k,0);
    ll int res=solve(v,prefix,0,n-1);
    cout<<res<<endl;
    return 0;
}