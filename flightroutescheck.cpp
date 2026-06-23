#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>to(n+1);
    vector<vector<int>>from(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        to[a].push_back(b);
        from[b].push_back(a);
    }
    queue<int>q;
    q.push(1);
    int count1=0;
    vector<int>seen(n+1,0);
    seen[1]=1;
    while(!q.empty()){
        int a=q.front();
        count1++;
        for(int b:to[a]){
            if(seen[b]==0){
                q.push(b);
                seen[b]=1;
               
            }
        }
        q.pop();
    }
    for(int i=1;i<=n;i++){
        if(seen[i]==0){
            cout<<"NO"<<endl;
            cout<<"1"<<" "<<i;
            return 0;
        }
    }
    vector<int>seen2(n+1,0);
    seen2[1]=1;
    q.push(1);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(int b:from[a]){
            if(seen2[b]==0){
                q.push(b);
                seen2[b]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(seen2[i]==0){
            cout<<"NO"<<endl;
            cout<<i<<" 1";
            return 0;
        }
    }
    cout<<"YES";
}