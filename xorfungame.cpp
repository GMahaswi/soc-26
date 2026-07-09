#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    
    while(q--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        
        // Find first '1' in s and t
        int fs = -1, ft = -1;
        for(int i = 0; i < n; i++) if(s[i]=='1'){ fs = i; break; }
        for(int i = 0; i < n; i++) if(t[i]=='1'){ ft = i; break; }
        
        // f(s) <= f(t) means:
        // - s is all zeros (fs==-1): only if t is also all zeros
        // - s has first 1 at fs: t must have first 1 at ft >= fs (or t all zeros)
        bool ok;
        if(fs == -1){
            // s is all zeros, f(s)=inf, need f(t)=inf too
            ok = (ft == -1);
        } else {
            // f(s)=fs, need f(t)>=fs, i.e ft==-1 (all zeros, inf) or ft>=fs
            ok = (ft == -1) || (ft >= fs);
        }
        
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}