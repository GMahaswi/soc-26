#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    
    vector<int>ans;
    while(t--){
        int a,b;
        cin>>a>>b;
        vector<int>veca(a+1);
        vector<int>vecb(b+1);
        unordered_set<int>aset;
        int cnt=0;
        for(int i=1;i<=a;i++){cin>>veca[i];
        aset.insert(veca[i]);
        }
        for(int i=1;i<=b;i++){cin>>vecb[i];
        if(aset.find(vecb[i])!=aset.end()){
            cnt++;
        }
        }
        int lefta=a-cnt;
        int leftb=b-cnt;
        if(lefta<=leftb){
            ans.push_back(2*lefta+1);
        }
        else if(lefta>leftb) {
            ans.push_back(2*leftb +2);
        }
    }
    for(int a:ans){
       
        cout<<a<<'\n';
    }
    return 0;
}