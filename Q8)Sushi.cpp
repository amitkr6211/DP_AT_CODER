#include<bits/stdc++.h>
using namespace std;
#define ll long long

double dp[301][301][301];

double sushi(ll int x, ll int y, ll int z, ll int n){
    // cout<<x<<" "<<y<<" "<<z<<endl;
    if(x==0 and y==0 and z==0)return 0;

    if(dp[x][y][z]!=-1.0){
        return dp[x][y][z];
    }
    double a=0;
    if(x>0)a=x*sushi(x-1,y,z,n);
    double b=0;
    if(y>0)b=y*sushi(x+1,y-1,z,n);
    double c=0;
    if(z>0)c=z*sushi(x,y+1,z-1,n);

    // cout<<a<<" "<<b<<" "<<c<<endl;

    return dp[x][y][z]=(n+a+b+c)/(x+y+z);
}
int main(){
    int n;
    cin>>n;

    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // memset(dp,
    int one=0,two=0,three=0;
    for(int i=0;i<n;i++){
        if(v[i]==1)one++;
        else if(v[i]==2)two++;
        else three++;
    }
    for(int i=0;i<301;i++){
        for(int j=0;j<301;j++){
            for(int k=0;k<301;k++){
                dp[i][j][k]=-1.0;
            }
        }
    }
    /*
    dp[one][two][three]=1+ p(one)*dp[one-1][two][three] + p(two)*dp[one+1][two-1][three] + p(three)*dp[one][two+1][three-1]+p(zero)*dp[one][two][three]

    dp[one][two][three]=(1+ p(one)*dp[one-1][two][three] + p(two)*dp[one+1][two-1][three] + p(three)*dp[one][two+1][three-1])

    p(one)=one/N;
    p(two)=two/N
    p(zero)= N-(one+two+three)/N= 1 - (one+two+three)/N
    1-p(zero)=(one+two+three)/N

    dp[one][two][three]=(N+ (one)*dp[one-1][two][three] + (two)*dp[one+1][two-1][three] + (three)*dp[one][two+1][three-1]) /(one+two +three)
    */
    double res=sushi(one,two,three,n);
    cout<<setprecision(15)<<res;
    return 0;
}