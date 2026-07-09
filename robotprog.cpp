#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,x,k;
        cin>>n>>x>>k;
        string s;
        cin>>s;
        int sum=0;
        int diff=-x;
        int zer=-1;
        int sec=0;
        int seci=-1;
        bool t=false;
        for(char c:s){
            sec++;
            if(c=='L'){
                sum=sum-1;
            }
            else {
                sum=sum+1;
            }
            if(sum==0&&zer==-1){
                zer=sec;
            }
            if(sum==diff&&!t){
                t=true;
                seci=sec;
            }
            
        }
        if(!t){
            cout<<"0";
        }
        else {
           
            int div=(k-seci);
            int num;
            if(zer==-1)num=0;
            else {
            num=div/zer;}
            cout<<num+1;
        }
        cout<<endl;
    }
}