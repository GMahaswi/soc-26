#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int myc=arr[k-1];
        int maxi=0;
        int grt=-1;
        for(int i=0;i<k-1;i++){
            if(arr[i]>myc){
                grt=i;
                break;
            }
        }
        if(grt==-1){
            int fromit=n;
            for(int i=k;i<n;i++){
                if(arr[i]>myc){
                    fromit=i;
                    break;
                }
            }
            maxi=fromit-1;
        }
        else {
            maxi=max(maxi,grt-1);
            int grti=-1;
            swap(arr[k-1],arr[grt]);
            for(int i=grt+1;i<k;i++){
                if(arr[i]>myc){
                    grti=i;
                    break;
                }
            }
            if(grt==0){
                grt=1;
            }
            maxi=max(maxi,grti-grt);
        }
        ans.push_back(maxi);
    }
    for(int a:ans)cout<<a<<'\n';
}