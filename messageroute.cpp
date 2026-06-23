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
    seen[1]=1;
    queue<pair<int,int>>q;
    q.push({1,1});
    vector<int>parent(n+1,0);
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        for(int i:v[p.first]){
            if(i==n){
                cout<<p.second+1<<endl;
                vector<int>rev;
                rev.push_back(n);
                int pre=p.first;
                while(pre!=1){
                    rev.push_back(pre);
                    pre=parent[pre];
                }
                rev.push_back(1);
                int ner=rev.size();
                for(int i=ner-1;i>=0;i--){
                    cout<<rev[i]<<" ";
                    if(i!=0)cout<<" ";
                    
                }
                return 0;
            }
            if(!seen[i]){
                seen[i]=1;
                q.push({i,p.second+1});
                parent[i]=p.first;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}