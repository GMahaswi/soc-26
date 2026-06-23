#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pq.push({b,a});
    }
    int ans=0;
    int curr=-1;
    while(!pq.empty()){
        if(pq.top()[1]>=curr){ans++;
        curr=pq.top()[0];
        }
        pq.pop();
    }
    cout<<ans;
}