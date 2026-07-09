#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        string s;
        cin>>s;
        string t;
        cin>>t;
        int i=0;
        int j=0;
        while(i<s.length()&&j<t.length()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else if(s[i]=='?'){
                s[i]=t[j];
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        if(j==t.length()){
            cout<<"YES"<<'\n';
            for(int i=0;i<s.length();i++){
                if(s[i]=='?')s[i]='a';
            }
            cout<<s<<'\n';
        }
        else {
            cout<<"NO"<<'\n';
        }
        
    }

}