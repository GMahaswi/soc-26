#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    
    vector<long long> h(n), s(n);
    
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    
    // dp[j] = max pages with budget exactly j
    vector<long long> dp(x + 1, 0);
    
    for(int i = 0; i < n; i++){
        // Traverse backwards to avoid using same book twice
        for(long long j = x; j >= h[i]; j--){
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    
    cout << dp[x] << endl;
    return 0;
}