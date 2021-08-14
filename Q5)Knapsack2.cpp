#include<bits/stdc++.h>
using namespace std;
#define ll long long
// ll int dp[102][100002];

/*
Here the constraints are different
 n <=100 and vi<=1000 , wt_sack is 10e9 
 so get min wt reqd using given values to reach a particular value
 and in the last row , check for max j such that dp[n-1][j]<=wt_sack 

*/

int main(){
    int n,w;
    cin>>n>>w;

    int tot_val=0;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        tot_val+=b;
        v.push_back({a,b});
    }

    // int dp[n][tot_val];
    vector<vector<ll int>> dp(n+1,vector<ll int>(tot_val+1,INT_MAX));
    // dp[i][j]= min_wt required to generate a value equal to j using i items  // subset sum (min_el required to make sum=x) 
    // []78475894789 , sum=98 , find whether this 98 can  subset sum, min_el 
    // ans = using all items ,try to get the maximum j such that dp[i][j]<=knapsack_wt 
    // i=n-1
       
          //0 1  ...2. 3. 4...............140
    //   0 0  inf  inf . .. . .......inf
    //   3 0  inf  inf 3  inf 
    //   4 0
    //   5 0
    // Analogous to subset sum 
    for(int i=0;i<=n;i++){
        dp[i][0]=0; // 0 items implies 0 wt reqd
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=tot_val;j++){
            if(v[i-1].second>j){
                //value is greater than target
                dp[i][j]=min(dp[i-1][j],dp[i][j]);
            }
            else{
                if(dp[i-1][j-v[i-1].second]!=INT_MAX)
                    dp[i][j]=min(dp[i-1][j],v[i-1].first+dp[i-1][j-v[i-1].second]);
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=tot_val;j++){
            if(dp[i][j]==INT_MAX){
                cout<<"* ";
            }
            else{
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    //last row
    ll int res=0;
    for(ll int j=tot_val;j>=0;j--){
        // cout<<dp[n][j]<<" "<<w<<endl;
        if(dp[n][j]<=w){
            // cout<<"vL "<<dp[n][j]<<endl;
            res=j;
            break;    
        }
    }
    cout<<res<<endl;
    return 0;
}