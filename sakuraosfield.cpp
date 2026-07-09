#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int s=1;
        int l=n-2;
        while(s<l){
            if(vec[s]==vec[s-1]||vec[l]==vec[l+1]){
                swap(vec[s],vec[l]);
            }
            s++;
            l--;
        }
        int dist=0;
        for(int i=0;i<n-1;i++){
            if(vec[i]==vec[i+1])dist++;
        }
        ans.push_back(dist);
    }
    for(int a:ans)cout<<a<<'\n';
}