#include<bits/stdc++.h>
using namespace std;
#define int long long
int overl(string a,string b){
        int ap=0;
        int bp=0;
        int al=a.length();
        int bl=b.length();
        int overl=0;
        while(ap<al&&bp<bl){
            if(a[ap]==b[bp]){
                bp++;
                ap++;
                overl++;
            }
            else {
                ap++;
            }
        }
        return overl;
}
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        string a,b;
        cin>>a;
        cin>>b;
        int al=a.length();
        int bl=b.length();
        int maxi=a.length()+b.length();
        for(int i=0;i<b.length();i++){
            int o=overl(a,b.substr(i));
              maxi=min(maxi,al+bl-o);
        }
      
        ans.push_back(maxi);
    }
    for(int a:ans)cout<<a<<'\n';

}