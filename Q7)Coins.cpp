#include<bits/stdc++.h>
using namespace std;
#define ll long long
double dp[3000][3000];
double solve(vector<double> &v, int index, int heads){
    int n=v.size();
    if(index==n){
        return 1;
    }
    int min_head=(n/2)+1-heads;
    if(dp[index][heads]!=-1.0){
        // cout<<dp[index][heads]<<endl;
        return dp[index][heads];
    }
    int rem_pos=n-index;

    // cout<<min_head<<" "<<rem_pos<<endl;
    if(rem_pos==min_head){
        //go with head only , no other choices left
        // cout<<v[index]<<endl;
        return dp[index][heads]=v[index]*solve(v,index+1,heads+1);
    }
    else{
        double a=v[index]*solve(v,index+1,heads+1);//heads
        double b=(1-v[index])*solve(v,index+1,heads);//heads
        return dp[index][heads]=a+b;
    }
}

int main(){
    int n;
    cin>>n;

    vector<double> v(n,0);
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<3000;i++){
        for(int j=0;j<3000;j++){
            dp[i][j]=-1.0;
        }
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // cout<<v[0]<<endl;
    double res=solve(v,0,0);
    cout<<setprecision(10)<<res<<endl;
    return 0;
}