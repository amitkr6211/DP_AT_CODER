#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll int dp[100005][102][2];
ll int solve(int index,int reqd, int d, string &s,bool constraint){
    int up=9;
    if(constraint){
        up=(int)s[index]-'0';
    }
    if(index==s.length()-1){
        ll int ans=0;
        for(int i=0;i<=up;i++){
            if(i%d==reqd){
                ans++;
            }
        }
        return ans;
    }
    if(dp[index][reqd][constraint]!=-1){
        return dp[index][reqd][constraint];
    }

    ll int res=0;
    if(constraint){
        char c=s[index];
        int t=(int)c-'0';
        for(int i=0;i<=t;i++){
            if(i==t){
                res=(res+solve(index+1,(d+reqd-i%d)%d,d,s,true)%mod)%mod;
            }
            else{
                res=(res+solve(index+1,(d+reqd-i%d)%d,d,s,false)%mod)%mod;
            }
        }
    }
    else{
        for(int i=0;i<=9;i++){
            res=(res+solve(index+1,(d+reqd-i%d)%d,d,s,false)%mod)%mod;
        }
    }
    return dp[index][reqd][constraint]=res%mod;
}
int main(){
    string s;
    cin>>s;
    int d;cin>>d;
    memset(dp,-1,sizeof(dp));
    int len=s.length();

    // ll int res=solve(len,0,d,s,false);
    ll int res=solve(0,0,d,s,true);

    
    cout<<(mod+res%mod-1)%mod<<endl;
    return 0;
}