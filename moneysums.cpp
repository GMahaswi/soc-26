#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

const int inv2 = modpow(2,MOD-2);;
int32_t main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum+=(vec[i]);
    }


    vector<int>dp(sum+1,0);
    dp[0]=1;
    int count=0;
    for(int i=n-1;i>=0;i--){
        int left=sum-vec[i];
        for(int j=left;j>=0;j--){
            if(dp[j+vec[i]]>0){
            continue;
            }
            else if(dp[j]>0){dp[j+vec[i]]=1;count++;}
            
           
        }
    }
    cout<<count<<endl;
    for(int j=1;j<=sum;j++){
        if(dp[j]>0)cout<<j<<" ";
    }
}