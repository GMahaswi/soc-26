#include<bits/stdc++.h>
using namespace std;
int dfs(int i,int j,vector<vector<int>>&seen,vector<vector<char>>&v,int n,int m,string s){
    
    if(i>=n||i<0||j>=m||j<0||v[i][j]=='#')return 0;
    if(seen[i][j]==1)return 0;
    seen[i][j]=1;
    if(v[i][j]='B'){
        cout<<"YES";
        cout<<s;
        return 1;
    }
    if(dfs(i+1,j,seen,v,n,m,s+'D'))return 1;
    if(dfs(i,j+1,seen,v,n,m,s+'R'))return 1;
    if(dfs(i-1,j,seen,v,n,m,s+'U'))return 1;
    if(dfs(i,j-1,seen,v,n,m,s+'L'))return 1;
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    vector<vector<int>>seen(n,vector<int>(m,0));
    int starti,startj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                starti=i;startj=j;
            }
        }
    }
    int ans=0;

    cout<<ans;

}