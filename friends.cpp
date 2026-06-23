#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>&v,vector<int>&seen,int ind){

    for(int i:v[ind]){
        if(seen[i]==seen[ind]){
            return false;
        }
        if(seen[i]!=0)continue;
        seen[i]=3-seen[ind];
        if(!dfs(v,seen,i))return false;
    }
    return true;
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
    vector<int>seen(n+1,0);
    for(int i=1;i<=n;i++){
        if(!seen[i]){
            seen[i]=1;
            if(
                !dfs(v,seen,i)){
                cout<<"IMPOSSIBLE";
                return 0;
            };
        }
    }

    for(int i=1;i<=n;i++){
        cout<<seen[i]<<" ";
    }
}