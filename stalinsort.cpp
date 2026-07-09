#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int a=n;
        for(int i=0;i<n;i++){
            int c=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    c++;
                }
            }
            a=min(a,c);
        }
        ans.push_back(a);
    }
    for(int a:ans)cout<<a<<'\n';
}