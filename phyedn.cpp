#include<bits/stdc++.h>
using namespace std;
int countDivisors(long long n,long long x) {
    int cnt = 0;
    for (long long i = 1; i * i <= n; i++) {
        
        if (n % i == 0) {
            if(i>=x)cnt++; // 'i' is a divisor
            if (i * i != n) {
                cnt++; // 'n / i' is the paired unique divisor
            }
        }
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int x,n;
        cin>>x>>n;
        int diff=x-n;
        if(diff%2!=0|diff<0){ans.push_back(0);continue;}
        int som=x+n-2;
        diff=diff/2;
        som=som/2;
        int div=0;
        div+=countDivisors(diff);
        div+=countDivisors(som);
        div-=countDivisors(gcd(diff,som));
        ans.push_back(div);
    }
    for(int a:ans)cout<<a<<endl;
}