#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        int sqt=sqrt(n);
        int a=0;
        for (int i=1;i<=(sqt);i++){
            if(n%i==0){
                a=a+2;
            }
        }
        if(sqt*sqt==n)a=a-1;
        ans.push_back(a);
    }
    for(int a:ans)cout<<a<<endl;
}