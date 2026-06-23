#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int x,y;
    cin>>x>>y;
    vector<vector<int>>seen(9,vector<int>(9,0));
    int all=0;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        seen[p.first][p.second]=1;
        int px=p.first;
        int py=p.second;

        all++;
        seen[px][py]=all;
        if(all==64)break;
        if(px+2<=8&&py+1<=8&&seen[px+2][py+1]==0){
            q.push({px+2,py+1});
            continue;
        }
        if(px+2<=8&&py-1>=1&&seen[px+2][py-1]==0){
            q.push({px+2,py-1});
            continue;
        }
        if(py+2<=8&&px+1<=8&&seen[px+1][py+2]==0){
            q.push({px+1,py+2});
            continue;
        }
        if(py+2<=8&&px-1>=1&&seen[px-1][py+2]==0){
            q.push({px-1,py+2});
            continue;
        }
        if(px-2>=1&&py+1<=8&&seen[px-2][py+1]==0){
            q.push({px-2,py+1});
            continue;
        }
        if(px-2>=1&&py-1>=1&&seen[px-2][py-1]==0){
            q.push({px-2,py-1});
            continue;
        }
        if(py-2>=1&&px+1<=8&&seen[px+1][py-2]==0){
            q.push({px+1,py-2});
            continue;
        }
        if(py-2>=1&&px-1>=1&&seen[px-1][py-2]==0){
            q.push({px-1,py-2});
            continue;
        }
    }
    for(int i=1;i<9;i++){
        for(int j=1;j<9;j++)cout<<seen[i][j]<<" ";
        cout<<endl;
    }
}