#include<bits/stdc++.h>
using namespace std;
long long func(int num,int a,int b){
    
    string s=to_string(num);
    int nl=s.length();
    int o=s[0]-'0';
    if(o>a&&o>b){
        long long ans=0;
        for(char c:s){
            ans=a+(ans*10);
            return ans;
        }
    }
    else if(o<a&&o<b){
        long long ans=0;
        for(char c:s){
            ans=b+(ans*10);
            return ans;
        }
    }
    else if(o==a){
        long long ans=0;
        for(int i=0;i<s.length();i++){
            if(i==0){
                ans=(ans*10)+b;
            }
            else{
                ans=(ans*10)+a;
            }
        }
        long long mpor=func(stoi(s.substr(1)),a,b);
        return (min(stoi(s.substr(1))-mpor),ans-num);
    }
    else if(o==b) {
        long long ans=0;
        for(int i=0;i<s.length();i++){
            if(i==0){
                ans=(ans*10)+a;
            }
            else{
                ans=(ans*10)+b;
            }
        }
        long long mpor=func(stoi(s.substr(1)),a,b);
        return (min(abs(stoi(s.substr(1))-mpor)),abs(ans-num));
    }
    else {
        
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,n;
        cin>>a>>n;
        vector<int>v(2);
        cin>>v[0]>>v[1];
        string s=to_string(a);
        for(char c:s){
            int po=c-'0';

        }
    }
}