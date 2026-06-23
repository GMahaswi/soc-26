#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>func(int n,int start){
    vector<int>ans;
    if(n==1){
        ans.push_back(1);
        return ans;
    }
    if(start==0){
       
        for(int i=2;i<=n;i+=2){
            ans.push_back(i);
        }
        if(n%2==0){
            for(int o:func(n/2,0)){
                ans.push_back(o*2 -1);
            }
        }
        else {
          
            for(int o:func((n/2)+1,1)){
                ans.push_back(o*2 -1);
            }
        }

    }
    else if(start==1){
         for(int i=1;i<=n;i+=2){
            ans.push_back(i);
        }
        if(n%2==0){
            
            for(int o:func(n/2,1)){
                ans.push_back(o*2 );
            }
        }
        else {
            for(int o:func(n/2,0)){
                ans.push_back(o*2);
            }
        }
    }
    return ans;

}
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,p;
        cin>>n>>p;
        vector<int>pres=func(n,0);
        if(p>pres.size()||p<=0){
            ans.push_back(-1);
        }
        else ans.push_back(pres[p-1]);
        cout<<pres[p-1]<<endl;
    }
    
}

