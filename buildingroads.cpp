#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&v,vector<int>&seen,int ind){

    for(int i:v[ind]){
        if(seen[i]==0){
            seen[i]=1;
        dfs(v,seen,i);}
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }
    vector<int>com;
    vector<int>seen(n+1,0);
    for(int i=1;i<=n;i++){
        if(!seen[i]){
            com.push_back(i);
            dfs(v,seen,i);
        }
    }
    int a=com.size();
    cout<<a-1<<endl;
    for(int i=1;i<a;i++){
        cout<<com[i-1]<<" "<<com[i]<<endl;
    }
}