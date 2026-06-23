#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>posi(n+1);
    int ans=n;
    for(int i=0;i<n;i++){
        posi[vec[i]]=i;
    }
    for(int i=1;i<=n-1;i++){
        if(posi[i]<posi[i+1])ans--;
    }
    vector<int>fans;
    while(m--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            
            fans.push_back(ans);
            continue;
        }
        int n1=vec[a-1];
        int n2=vec[b-1];
        if(abs(n1-n2)==1){
            int ma=max(n1,n2);
            int mi=min(n1,n2);
            if(posi[ma]>posi[mi]){
                ans++;
            }
            else ans--;
            if(mi!=1){
                if(posi[mi-1]<posi[mi]&&posi[ma]<posi[mi-1])ans++;
                else if(posi[mi-1]>posi[mi]&&posi[ma]>posi[mi-1])ans--;
            }
            if(ma!=n){
                if(posi[ma+1]<posi[ma]&&posi[mi]<posi[ma+1])ans--;
                else if(posi[ma+1]>posi[ma]&&posi[mi]>posi[ma+1])ans++;
            }
        }
        else {
        if(n1!=1){
            if(posi[n1-1]<posi[n1]&&posi[n2]<posi[n1-1])ans++;
            else if(posi[n1-1]>posi[n1]&&posi[n2]>posi[n1-1])ans--;
        }
         if(n1!=n){
            if(posi[n1+1]<posi[n1]&&posi[n2]<posi[n1+1])ans--;
            else if(posi[n1+1]>posi[n1]&&posi[n2]>posi[n1+1])ans++;
        }
        if(n2!=1){
            if(posi[n2-1]<posi[n2]&&posi[n1]<posi[n2-1])ans++;
            else if(posi[n2-1]>posi[n2]&&posi[n1]>posi[n2-1])ans--;
        }
         if(n2!=n){
            if(posi[n2+1]<posi[n2]&&posi[n1]<posi[n2+1])ans--;
            else if(posi[n2+1]>posi[n2]&&posi[n1]>posi[n2+1])ans++;
        }
    }
        fans.push_back(ans);
        vec[a-1]=n2;
        vec[b-1]=n1;
        int vi=posi[n1];
        posi[n1]=posi[n2];
        posi[n2]=vi;
        
    }
    for(int ver:fans){
        cout<<ver<<endl;
    }
}