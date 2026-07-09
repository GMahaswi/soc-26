#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int start,vector<int>&totseen,vector<int>&con, vector<int>&colr,int ind,int &black,vector<int>&forp,int val){
    if(ind!=start){
        if(val==0){
        val=1;
        start=ind;
        }       
        totseen[ind]=1;
        forp.push_back(ind);     
        if(colr[ind]==0)black++;
        dfs(start,totseen,con,colr,con[ind],black,forp,val);
    }
    
}
int32_t main(){
    int t;
    cin>>t;
    vector<vector<int>>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>perm(n+1);
        perm[0]=0;
        for(int i=1;i<=n;i++){
            cin>>perm[i];
        }
        string s;
        cin>>s;
        vector<int>colr(n+1);
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'){
                colr[perm[i]]=1;
            }
            else colr[perm[i]]=0;
        }
        
        vector<int>con(n+1,0);
        for(int i=1;i<=n;i++){
            con[perm[i]]=perm[perm[i]];
        }
        vector<int>anslevel(n,0);
        vector<int>totseen(n+1,0);
        for(int i=1;i<=n;i++){
            if(totseen[i]==0){
            
            vector<int>forp;
            int black=0;
            dfs(0,totseen,con,colr,i,black,forp,0);
        
            for(int j:forp){
                
                anslevel[j-1]=black;
            }
            }
        }
        ans.push_back(anslevel);
    }
    for(auto an:ans){
        for(int i:an)cout<<i<<" ";
        cout<<'\n';
    }
}
