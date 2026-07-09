#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int tr;
    cin>>tr;
    vector<bool>ans;
    while(tr--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<char>vec(n+1);
        for(int i=1;i<=n;i++)cin>>vec[i];

        bool t=true;
        int i=0;
        queue<int>crocs;
        queue<int>logs;
        int maxcroc=0;
        for(int j=1;j<=n;j++){
            if(vec[j]=='C'){
                maxcroc=j;
                crocs.push(j);
            }
            else if(vec[j]=='L'){
                logs.push(j);
            }
        } 
        int tswim=0;
        while(i<=n){       
            if(m+i>n){            
                break;
            }
            if(logs.empty()){
                i=m+i;
                if(maxcroc>=(i)){ 
                    t=false;
                }
                int diff=(n+1-i);
                tswim+=(diff);
                if(tswim>k)t=false;
                break;
            }
            int flog=n+1;
            if(!logs.empty()) flog=logs.front();
            if(i+m>=flog){i=flog;
            logs.pop();
            continue;
            }
            
            while(!crocs.empty()){
                if(i>crocs.front()){
                    crocs.pop();

                }
                else break;
            }
            int cp=n+3;
            if(!crocs.empty())cp=crocs.front();        
            if(flog>cp){ 
                t=false;
                break;
            }
            if(!crocs.empty()){
                cp=crocs.front();
            }
            if(flog>cp){
                if()
                t=false;
                break;
            }
            
            else {
                i=i+m;
                tswim+=(flog-i);
                if(tswim>k){
                    t=false;
                    break;
                }
                else {
                    i=flog;
                }
            }
        }

        ans.push_back(t);
    }
    for(int a:ans){
        if(a)cout<<"yes";
        else cout<<"No";
        cout<<endl;
    }
}