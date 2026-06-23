#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>deps(n);
    vector<int>needs(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        deps[a-1].push_back(b-1);
        needs[b-1]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(needs[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int f=q.front();
        ans.push_back(f);
        q.pop();
        for(int d:deps[f]){
            needs[d]--;
            if(needs[d]==0){
                q.push(d);
            }
        }
    }
    if(ans.size()!=n){
        cout<<"IMPOSSIBLE";
    }
    else {
        for(int a:ans)cout<<a+1<<" ";
    }
}