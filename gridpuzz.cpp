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
        queue<int>q;
        int a=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                a++;
            if(arr[i]<=2){
                q.push(i);
            }
            }
        }
        ans.push_back(a);
        
        while(!q.empty()){
            int to=q.front();
            if(arr[to]<=0)a--;
            else {
                arr[i]-=2;
                if(to==0){
                    if(arr[i+1]!=0){
                        arr[i+1]-=2;
                        if(arr[i+1]<=2)q.push(i+1);
                    }
                    
                }
                else if(to==n-1){
                    if(arr[i-1]!=0){
                        arr[i-1]-=2;
                        if(arr[i-1]<=2)q.push(i-1);
                    }
                    
                }
                else {
                    if(arr[i-1]!=0||arr[i+1]!=0){
                        if(arr[i-1]==0){
                            arr[i+1]-=2;
                        if(arr[i+1]<=2)q.push(i+1);
                        }
                        else if(arr[i+1]==0){
                            arr[i-1]-=2;
                            if(arr[i-1]<=2)q.push(i-1);
                        }
                        else {
                            
                        }
                    }
                }
            }
        }
    }
    for(int a:ans)cout<<a<<'\n';
}