#include<bits/stdc++.h>
using namespace std;
void dist(int i,int j,vector<vector<int>>&seen,vector<vector<int>>v){
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>vec(n,vector<int>(m));
    int si;
    int se;
    vector<vector<pair<int,int>>>monsters(n,vector<pair<int,int>>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='#'){
                vec[i][j]=0;
            }else (v[i][j]=='.'){
                vec[i][j]=1;
            }else (v[i][j]=='M'){
                monsters.push_back({i,j});
                vec[i][j]=-1;
                
            }else{
                vec[i][j]=1;
                si=i;sj=j;
            }
        }
    }
    vector<vector<int>>vec(n,vector<int>(m,0));
    queue<vector<int>>q;
    vector<int>vi;
    vi.push_back(si);
    vi.push_back(sj);
    
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m));
    q.push(vi);
    while(!q.empty()){
        vector<int>vi=q.front();
        int i=vi[0];
        int j=vi[1];
        q.pop();
        if(seen[i][j]==1){
            continue;
        }
        if(i==0||i==n-1||j==0||j==n-1){
            for()
            return 0;
        }
        else{
            if(vec[i+1][j])
        }

    }
}