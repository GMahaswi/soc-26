#include<bits/stdc++.h>
using namespace std;
#define int long long
bool func(){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            diff[i]=a[i]-b[i];
        }
        vector<int>maxinc(n,0);
        vector<int>maxdec(n,0);
        if(diff[0]>0)return 0;
        maxinc[0]=-diff[0];
        for(int i=1;i<n;i++){
            int d=diff[i];
            int maxi=maxinc[i-1];
            int maxd=maxdec[i-1];
            maxdec[i]=maxi;
            if(diff[i]>0){
                if(maxdec[i]<diff[i])return false;
            }
             maxinc[i]=maxdec[i]-diff[i];
        }
        return true;

}
int32_t main(){
    int t;
    cin>>t;
    
    vector<int>ans;
    while(t--){
        
        
        ans.push_back(func());

    }
    for(int a:ans){
       
        if(a==0)cout<<"NO";
        else cout<<"YES";
        cout<<'\n';
    }
    return 0;
}