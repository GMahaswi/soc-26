#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define pb push_back
const int mod = 1e9 + 7;
const int inf= 1e18;
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
int main(){
    int n;
    cin>>n;
    vector<vector<string>>v(n+1);
    v[2]={"10","11","01","00"};
    v[1]={"1","0"};
    for(int i=3;i<=n;i++){
        for(string s:v[i-2]){
            string a="0"+s+"0";
            string b="0"+s+"1";
            string c="1"+s+"0";
            string d="1"+s+"1";
            v[i].pb(a);
            v[i].pb(b);
            v[i].pb(c);
            v[i].pb(d);
        }

    }
    sort(v[n].begin(),v[n].end());
    for(string  s:v[n]) cout<<s<<endl;
}