#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(){
     int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        map<int,vector<int>>mp;  
        for(int i=0;i<n;i++){
            int rem=a[i]%k;
            mp[rem].push_back(a[i]);
        }
        if(n%2==0){
            int ans=0;
            for(auto p:mp){
                
                int sz=p.second.size();
                if(sz%2!=0)return -1;
                else {
                    for(int i=0;i<sz;i+=2){   
                        ans+=((p.second[i+1]-p.second[i])/k);
                    }
                }
            }
            return ans;
        }
        else {
            int ans=0;
            bool t=false;
            for(auto p:mp){
                int sz=p.second.size();
                if(sz%2!=0){
                    if(t)return -1;
                    else {
                        t=true;
                        vector<int>v=p.second;
                        int m = v.size();
                vector<long long> pre(m + 1, 0), suf(m + 1, 0);

        // // pre[i] tracks pairing from left to right (step by 2)
                for (int i = 1; i < m; i += 2) {
                    pre[i] = (v[i] - v[i - 1]) / k;
                    if (i > 1) pre[i] += pre[i - 2];
                                }

                // suf[i] tracks pairing from right to left (step by 2)
                for (int i = m - 2; i >= 0; i -= 2) { // <-- Changed --i to i -= 2
                    suf[i] = (v[i + 1] - v[i]) / k;
                    if (i + 2 < m) suf[i] += suf[i + 2];
                }

                long long best = 1e18;
                for (int skip = 0; skip < m; skip += 2) {
                    int current_cost = 0;
                    if (skip > 0) current_cost += pre[skip - 1];       // Safe check for left side
                    if (skip + 1 < m) current_cost += suf[skip + 1];   // Safe check for right side
                    best = min(best, current_cost);
                }
    ans += best;
                    }
                }
                else {
                    for(int i=0;i<sz;i+=2){
                        ans+=(p.second[i+1]-p.second[i])/k;
                    }
                }
            }
            return ans;
        }
}
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int a=func();

        ans.push_back(a);
    }
    for(int a:ans)cout<<a<<'\n';

}