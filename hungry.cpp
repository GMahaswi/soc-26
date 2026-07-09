#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>answer;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>vec(n);
        int sum=0;
        int ans=0;
        vector<int>prefix;
        
        for(int i=0;i<n;i++){
            cin>>vec[i];
            sum=(sum+vec[i]);
            prefix.push_back(sum);
        }
        vector<int>dp(n+1,0);
        int fors=0;
        for(int i=n-1;i>=0;i--){
            int search=x;
            if(i!=0)search+=prefix[i-1];
            auto it=upper_bound(prefix.begin(),prefix.end(),search);
            if(it!=prefix.end()){
                int j=it-prefix.begin();
                dp[i]=1+dp[j+1];
            }
            fors=fors+dp[i];
        }
        int tot=(n*(n+1))/2;
        tot=tot-fors;
        answer.push_back(tot);
    }
    for(int a:answer)cout<<a<<'\n';
}