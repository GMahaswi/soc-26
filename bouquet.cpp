#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        
        map<int,int> mp;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            mp[x]++;
        }
        
        int maxi = 0;
        
        auto prev_it = mp.begin();
        // Single value case
        for(auto& [val,cnt] : mp){
            maxi = max(maxi, min(cnt, m/val) * val);
        }
        
        // Consecutive pair case
        auto it = next(mp.begin());
        while(it != mp.end()){
            auto& [v1, c1] = *prev_it;
            auto& [v2, c2] = *it;
            
            if(v2 == v1 + 1){
                for(int take2 = 0; take2 <= c2; take2++){
                    int spent2 = take2 * v2;
                    if(spent2 > m) break;
                    int take1 = min(c1, (m - spent2) / v1);
                    maxi = max(maxi, spent2 + take1*v1);
                }
            }
            prev_it = it;
            it++;
        }
        
        cout << maxi << "\n";
    }
}