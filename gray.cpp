#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define pb push_back
const int mod = 1e9 + 7;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
int main(){
    int n;
    cin>>n;
    vector<vector<string>>v(n+1);
    
    v[1]={"1","0"};
    if(n==1){
    
          for(string  s:v[n]) cout<<s<<endl;
          return 0;
    }
    v[2]={"10","11","01","00"};
    for(int i=3;i<=n;i++){
        for(string s:v[i-1]){
            string a="0"+s;


            v[i].pb(a);

        }
        reverse(v[i].begin(),v[i].end());
        for(string s:v[i-1]){
            string a="1"+s;
            v[i].pb(a);
        }
    }
    
    for(string  s:v[n]) cout<<s<<endl;
}