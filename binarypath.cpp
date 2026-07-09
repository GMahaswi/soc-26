#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int32_t main(){
    int t;
    cin>>t;
    
    vector<int>anss;
    while(t--){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        vector<int>a1(n+1);
        vector<int>a2(n+1);
        for(int i=1;i<=n;i++){
            a1[i]=s1[i-1]-'0';
        }
        for(int i=1;i<=n;i++){
            a2[i]=s2[i-1]-'0';
        }
        


        string s="";
        int lst=0;
        int cnt=0;
        int fin=n;

        for(int i=1;i<=n-1;i++){
            if(a1[i+1]<a2[i]){
                lst=i;
            }   
            else if(a1[i+1]>a2[i]){
                fin=i;
                break;
                
            }      
        }
        string suffix=to_string(a2[n]);
      
        for(int i=n-1;i>=fin;i--){
            suffix=to_string(a2[i])+suffix;
        }
        string prefix=to_string(a1[1]);
        for(int i=2;i<=fin;i++){
            prefix=prefix+to_string(a1[i]);
        }
        cnt=fin-lst;
        s=prefix+suffix;
        cout<<s<<endl;
        cout<<cnt<<endl;
        
    }
    for(int a:anss){
       
        cout<<a<<'\n';
    }
    return 0;
}