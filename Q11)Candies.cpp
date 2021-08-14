#include<bits/stdc++.h>
using namespace std;
#define ll long long
// static ll int mod= 10e9+7;
#define mod 1000000007
// int dp[100002];
void print(vector<ll int> &v){
    for(int i=0;i<(int)v.size();i++){
        cout<<v[i]<< " ";
    }
    cout<<endl;
}
// ll int dp[100002][102];
// ll int solve(vector<ll int> &v, ll int k, int index){
//     // cout<<k<<endl;
//     if(dp[k][index]!=-1){
//         return dp[k][index];
//     }
//     if(k==0){
//         // print(v);
//         return 1;
//     }
//     if(index==(int)v.size()){
//         return 0;
//     }
//     ll int ans=0;
//     ll int factor=min(v[index],k);
//     for(int i=0;i<=factor;i++){
//         v[index]-=i;
//         ans+=solve(v,k-i,index+1);
//         v[index]+=i;
//     }
//     return dp[k][index]=ans;
// }
int main(){
    int n,k;
    cin>>n>>k;
    // memset(dp,-1,sizeof(dp));
    vector<ll int> v(n,0);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    // ll int res=solve(v,k,0);
    ll int dp[n][k+1];
    memset(dp,-1,sizeof(dp));
    for(int j=0;j<k+1;j++){
        if(j<=v[0]){
            dp[0][j]=1;
        }
        else{
            dp[0][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<k+1;j++){
            dp[i][j]=(dp[i][j-1]%mod+dp[i-1][j]%mod)%mod;
            if(j-1-v[i]>=0){
                dp[i][j]=(dp[i][j]%mod - dp[i-1][j-1-v[i]]%mod +mod)%mod;
            }
        }
    }

    cout<<dp[n-1][k]%mod<<endl;
    return 0;
}