#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dfs(vector<int> v[], int src, vector<int> &lph, vector<int> &visited){
    visited[src]=1;
    for(int i=0;i<v[src].size();i++){
        int new_v=v[src][i];
        if(visited[new_v]==-1){
            int t=dfs(v,new_v,lph,visited);
            lph[src]=max(lph[src],1+t);
        }
        else{
            lph[src]=max(lph[src],1+lph[new_v]);
        }
    }
    if(lph[src]==-1){
        lph[src]=0;
    }
    return lph[src];
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<int> v[n+1];

    for(int i=0;i<m;i++){
        int src,dest;
        cin>>src>>dest;
        v[src].push_back(dest);
    }

    vector<int> lph(n+1,-1);
    vector<int> visited(n+1,-1);

    for(int i=1;i<=n;i++){
        if(lph[i]==-1){
            lph[i]=dfs(v,i,lph,visited);
        }
    }
    cout<<*max_element(lph.begin(),lph.end());
    return 0;
}