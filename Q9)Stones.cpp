#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100002];
bool solve(vector<int> &v, int k){
    // cout<<k<<endl;
    bool res=false;
    if(dp[k]!=-1){
        // cout<<"f"<<endl;
        return dp[k];
    }
    for(int i=0;i<(int)v.size();i++){
        if(v[i]!=-1 and v[i]<=k){
            int val=v[i];
            // v[i]=-1;
            bool t=solve(v,k-val);
            // v[i]=val;
            if(t==false){
                res=true;
                break;
            }
        }
    }
    if(res)return dp[k]=true;
    return dp[k]=false;
}
int main(){
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    vector<int> v(n,0);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // cout<<v[0]<<endl;
    // double res=solve(v,0,0);
    bool res=solve(v,k);
    if(res){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }
    return 0;
}