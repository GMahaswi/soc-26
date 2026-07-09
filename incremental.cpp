#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    
    
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int>black(m);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<m;i++){
            cin>>black[i];
            pq.push(black[i]);
        }
        unordered_set<int>ans;
        int beforelast=1;
        if(s[0]=='B'){
            int lst=1;
            while(!pq.empty()&&pq.top()<=lst+1){
                lst=pq.top();
               
                ans.insert(lst);
                pq.pop();
            }
            
            pq.push(lst+1);
        }
        else {
            int now=2;
            while(!pq.empty()&&pq.top()<now){
                ans.insert(pq.top());
                pq.pop();
            }
            if(pq.empty()||pq.top()!=now)pq.push(now);
        }
        for(int i=2;i<=n;i++){
            int curr=beforelast;
            if(s[i-2]=='B'){
                while(!pq.empty()&&pq.top()<=curr+1){
                    curr=pq.top();
                    ans.insert(curr);
                    pq.pop();
                }
                curr++;
                
            }
            else {
                curr++; 
            }
            beforelast=curr;
            if(i==n)cout<<curr<<endl;
            if(s[i-1]=='B'){
                while(!pq.empty()&&pq.top()<=curr+1){
                    curr=pq.top();
                    ans.insert(curr);
                    pq.pop();
                }
                curr++;
                pq.push(curr);
            
            }
            else {
                curr++;
                while(!pq.empty()&&pq.top()<curr){
                    ans.insert(pq.top());
                    pq.pop();
                }
                if(pq.empty()||pq.top()!=curr)pq.push(curr);
            }

        }
        while(!pq.empty()){
            ans.insert(pq.top());
            pq.pop();
        }
        cout<<ans.size()<<endl;
        vector<int>an;
        for(int a:ans)an.push_back(a);
        for(int i=an.size()-1;i>=0;i--){
            cout<<an[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}