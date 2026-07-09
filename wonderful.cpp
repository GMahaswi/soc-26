#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>heights(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>heights[i][j];
            }
        }
        vector<int>a(n);
        vector<int>b(n);

        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        bool t=true;
        vector<int>diff(n);
        vector<int>left(n,2);
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                if(j!=0){
                    if(heights[i][j]==heights[i][j-1]){
                        t=false;
                        break;
                    }
                }
                int max=
                int min=
                if(heights[i][j])
            }
            if(!t)break;
        }
        if(!t){
            cout<<"-1"<<endl;
            continue;
            
        }
    }
}