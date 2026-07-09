#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        int last=0;
        for(int i=0;i<n;i++){
            int pres=vec[i];
            int d=last/pres;
            last=((d+1)*pres);
        }
        ans.push_back(last);
    }
    for(int a:ans)cout<<a<<endl;
}