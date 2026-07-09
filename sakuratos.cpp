#include<bits/stdc++.h>
using namespace std;
#define int long long
int inf=1e9+7;
int modpow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int sum=0;
        int sqrsum=0;
        for(int i=0;i<n;i++){sum+=vec[i];
        int sqr=vec[i]*vec[i];
        sqrsum+=sqr;
        }
        int a=(sum)*sum;
        a=a-(sqrsum);
        a=a/2;
        int c=(n*(n-1))/2;
        if(a%c==0)a=a/c;
        else {
            c=modpow(c,inf-2,inf);
            a=(a*c)%inf;
        }
        a=a%inf;
        ans.push_back(a);
    }
    for(int a:ans)cout<<a<<'\n';
    
    }