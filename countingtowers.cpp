#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int>v;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>v(n+1,vector<int>(n+1,0));
        v[0][0]=1;
        v[1][1]=2;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0&&j==0)continue;
                if(i==1&&j==1)continue;
                if(i==j){
                    
                    for(int i1=0;i1<i;i1++){
                        v[i][j]+=(v[i1][i1]);
                    }
                    for(int i1=0;i1<j;i1++){
                        v[i][j]+=(v[i][i1]);
                    }
                  

                }
                else if(i>j){
                    for(int i1=0;i1<i;i1++){
                        v[i][j]+=(v[i1][j]);
                    }
                }
                else {
                    for(int i1=0;i1<j;i1++){
                        v[i][j]+=(v[i][i1]);
                    }
                }
            }
        }
        cout<<v[n][n]<<endl;
        }
}