#include<bits/stdc++.h>
using namespace std;
#define ll long long
// static ll int mod= 10e9+7;
#define mod 1000000007
// unordered_map<pair<int,int>,ll int> mp;
ll int dp[22][(1<<22)];
// ll int solve(vector<vector<int>>&v, vector<int> &visited, int index){
//     int n=visited.size();
//     if(index==n){
//         return 1;
//     }
//     if(mp.find({index,visited})!=mp.end()){
//         // cout<<"yups"<<endl;
//         return mp[{index,visited}];
//     }
//     ll int res=0;
//     for(int i=0;i<v[index].size();i++){
//         if(v[index][i]==1 and visited[i]==-1){
//             visited[i]=1;
//             res=(res%mod+solve(v,visited,index+1)%mod)%mod;
//             visited[i]=-1;
//         }
//     }
//     return mp[{index,visited}]=res%mod;
// }

ll int solve(vector<vector<int>>&v, int state, int index){
    int n=v.size();
    if(index==n){
        return 1;
    }
    if(dp[index][state]!=-1){
        return dp[index][state];
    }
    ll int res=0;
    for(int i=0;i<(int)v[index].size();i++){
        if(v[index][i]==1 and ((state & (1<<i))!=0)){
           
            //unset ith bit 0
            state=(state & (~(1<<i)));
           
            res=(res%mod+solve(v,state,index+1)%mod)%mod;
           
            //set ith bit 
            state=(state | (1<<i));
        }
    }
    return dp[index][state]=res%mod;
}

int main(){
    int n;
    cin>>n;
    // mp.clear();
    memset(dp,-1,sizeof(dp));
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    // vector<int> visited(n,-1);
    // ll int res=solve(v,visited,0);
    int state=((1<<n) -1);
    ll int res=solve(v,state,0);
    cout<<res<<endl;
    return 0;
}