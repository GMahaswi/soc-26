#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<vector<int>>v(t);
    for(int j=0;j<t;j++){
        int a;
        cin>>a;
    
        int arr[a];
        
        int f=1;
        vector<int>pre((2*a)+1,0);
        for(int i=0;i<a;i=i+1){
            if(i==0){
                arr[i]=1;
                pre[1]=1;
                f++;
            }
            else{
                while(pre[f]==1){
                    f++;
                }
                arr[i]=f;
                pre[f]=1;
                if(arr[i]+arr[i-1]<=(2*a)){
                    pre[arr[i]+arr[i-1]]=1;
                }
            }
        }
        for(int i:arr){
            v[j].push_back(i);
        }
    
    }
    for(int j=0;j<t;j++){
        for(int e:v[j]){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}