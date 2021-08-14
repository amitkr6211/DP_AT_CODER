#include<bits/stdc++.h>
using namespace std;
#define ll long long
// static ll int mod= 10e9+7;
#define mod 1000000007
ll int dp[100003][3];
ll int solve(vector<int> v[], int src, int prev_color, int parent){
    ll int ans=0;
    if(dp[src][prev_color]!=-1){
        return dp[src][prev_color];
    }
    //filling the cur vert with white
    ll int res=1;
    for(int i=0;i<(int)v[src].size();i++){
        int new_vert=v[src][i];
        if(new_vert==parent)continue;
        ll int t=solve(v,new_vert,0,src);
        res=(res%mod*t%mod)%mod;
    }
    ll int res2=0;
    if(prev_color!=1){
        res2=1;
        //can fill the cur vert with black
        for(int i=0;i<(int)v[src].size();i++){
            int new_vert=v[src][i];
            if(new_vert==parent)continue;
            ll int t=solve(v,new_vert,1,src);
            res2=(res2%mod*t%mod)%mod;
        }
    }
    ans=(res%mod+res2%mod)%mod;
    return dp[src][prev_color]=ans%mod;
}
int main(){
    int n;
    cin>>n;
    
    vector<int> v[n+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++){
        int src,dest;
        cin>>src>>dest;
        v[src].push_back(dest);
        v[dest].push_back(src);
    }
    
    ll int res=solve(v,1,2,-1);
    cout<<res%mod<<endl;
    return 0;
}