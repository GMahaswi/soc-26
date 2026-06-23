#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    vector<vector<int>>v(a,vector<int>(a,INT_MAX));
    v[0][0]=0;
    queue<pair<int,int>>q;
    vector<vector<int>>seen(a,vector<int>(a,0));
    q.push({0,0});
    seen[0][0]=1;
    while(!q.empty()){
        int f=q.front().first;
        int s=q.front().second;
        q.pop();
        int val=v[f][s];
        if(f+2<a){
        if(s-1>=0){
            v[f+2][s-1]=min(val+1,v[f+2][s-1]);
            if(seen[f+2][s-1]!=1)q.push({f+2,s-1});
            seen[f+2][s-1]=1;
        }
        if(s+1<a){
            v[f+2][s+1]=min(val+1,v[f+2][s+1]);
            if(seen[f+2][s+1]!=1)q.push({f+2,s+1});
            seen[f+2][s+1]=1;
        }
    }
    if(f-2>=0){
        if(s-1>=0){
            v[f-2][s-1]=min(val+1,v[f-2][s-1]);
            if(seen[f-2][s-1]!=1)q.push({f-2,s-1});
            seen[f-2][s-1]=1;
        }
        if(s+1<a){
            v[f-2][s+1]=min(val+1,v[f-2][s+1]);
            if(seen[f-2][s+1]!=1)q.push({f-2,s+1});
            seen[f-2][s+1]=1;
        }
    }
    if(s+2<a){
        if(f-1>=0){
            v[f-1][s+2]=min(val+1,v[f-1][s+2]);
            
            if(seen[f-1][s+2]!=1)q.push({f-1,s+2});
            seen[f-1][s+2]=1;
        }
        if(f+1<a){
            v[f+1][s+2]=min(val+1,v[f+1][s+2]);
            
            if(seen[f+1][s+2]!=1)q.push({f+1,s+2});
            seen[f+1][s+2]=1;
        }
    }
    if(s-2>=0){
        if(f-1>=0){
            v[f-1][s-2]=min(val+1,v[f-1][s-2]);
            
            if(seen[f-1][s-2]!=1)q.push({f-1,s-2});
            seen[f-1][s-2]=1;
        }
        if(f+1<a){
             v[f+1][s-2]=min(val+1,v[f+1][s-2]);
            
            if(seen[f+1][s-2]!=1)q.push({f+1,s-2});
            seen[f+1][s-2]=1;
        }
    }
    
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}