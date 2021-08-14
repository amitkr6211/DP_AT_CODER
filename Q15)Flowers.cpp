#include<bits/stdc++.h>
using namespace std;
#define ll long long
// static ll int mod= 10e9+7;
#define mod 1000000007
// unordered_map<string,ll int> mp;
// ll int solve(vector<int> &ht, vector<int> &bt, int index, int prev_max){
//     if(index==(int)ht.size()){
//         return 0;
//     }
//     string key=to_string(index)+"."+to_string(prev_max);
//     if(mp.find(key)!=mp.end()){
//         return mp[key];
//     }
//     if(ht[index]<prev_max){
//         //only one choice that is to delete this
//         return mp[key]=bt[index]+solve(ht,bt,index+1,prev_max);
//     }
//     else{
//         //2 options 
//         ll int a=bt[index]+solve(ht,bt,index+1,prev_max);
//         ll int b=solve(ht,bt,index+1,ht[index]);
//         return mp[key]=min(a,b);
//     }
// }
int main(){
    int n;
    cin>>n;
    
    vector<int> ht(n,0);
    vector<int> bt(n,0);
    for(int i=0;i<n;i++)cin>>ht[i];
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    vector<ll int> dp(n,0);
    map<ll int ,ll int> mp; // ht -> bt
    dp[0]=bt[0];
    mp[ht[0]]=bt[0];
    ll int ans=dp[0];
    for(int i=1;i<n;i++){
        dp[i]=bt[i];
        //lower bound 
        auto it=mp.lower_bound(ht[i]);
        if(it!=mp.begin()){
            it--;
            dp[i]+=it->second;
        }
        it=mp.upper_bound(ht[i]);
        while(it!=mp.end()){
            if(it->second<=dp[i]){
                auto t=it;
                it++;
                mp.erase(t); 
            }
            else{
                break;
            }
        }
        mp[ht[i]]=dp[i];
        ans=max(ans,dp[i]);
    }
    // for(int i=0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}