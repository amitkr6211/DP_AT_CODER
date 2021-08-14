#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll int dp[102][100002];

ll int solve(vector<pair<int,int>> &v, int index, int wt_sack){
    if(index==v.size()){
        return 0;
    }
    if(dp[index][wt_sack]!=-1){
        return dp[index][wt_sack];
    }
    
    // 2 options , don't take the cur item , or take the cur_item
    //don't take

    ll int a=solve(v,index+1,wt_sack);
    ll int b=INT_MIN;
    ll int cur_wt=v[index].first;
    // cout<<"cur_wt ="<<cur_wt<<"    wt_sack= "<<wt_sack<<endl;
    if(cur_wt<=wt_sack){
        b=v[index].second+solve(v,index+1,wt_sack-cur_wt);
    }

    return dp[index][wt_sack]=max(a,b);
}
int main(){
    int n,w;
    cin>>n>>w;
    memset(dp,-1,sizeof(dp));
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    ll int res=solve(v,0,w);
    cout<<res<<endl;
    return 0;
}