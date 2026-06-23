#include<bits/stdc++.h>
using namespace std;
vector<int>func(int n,int start){
    vector<int>ans;
    if(n==1){
        ans.push_back(1);
        return ans;
    }
    if(start==0){
       
        for(int i=2;i<=n;i+=2){
            ans.push_back(i);
        }
        if(n%2==0){
            vector<int>out=func(n/2,0);
            for(int o:out){
                ans.push_back(o*2 -1);
            }
        }
        else {
            vector<int>out=func((n/2)+1,1);
            for(int o:out){
                ans.push_back(o*2 -1);
            }
        }

    }
    else if(start==1){
         for(int i=1;i<=n;i+=2){
            ans.push_back(i);
        }
        if(n%2==0){
            vector<int>out=func(n/2,1);
            for(int o:out){
                ans.push_back(o*2 );
            }
        }
        else {
            vector<int>out=func(n/2,0);
            for(int o:out){
                ans.push_back(o*2);
            }
        }
    }
    return ans;

}
int main(){
    int n;
    cin>>n;
    for(int a:func(n,0)){
        cout<<a<<" ";
    }
}

