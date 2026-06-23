#include<bits/stdc++.h>
using namespace std;
int dfs(int i,int j,vector<vector<int>>&seen,vector<vector<char>>&v,int n,int m){
    
    if(i>=n||i<0||j>=m||j<0||v[i][j]=='#')return 0;
    if(seen[i][j]==1)return 0;
    seen[i][j]=1;
    dfs(i+1,j,seen,v,n,m);
    dfs(i,j+1,seen,v,n,m);
    dfs(i-1,j,seen,v,n,m);
    dfs(i,j-1,seen,v,n,m);
    return 1;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    vector<vector<int>>seen(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(seen[i][j]==0&&v[i][j]=='.'){
                ans++;
                dfs(i,j,seen,v,n,m);
            
            }
    
        }
    }
    cout<<ans;

}