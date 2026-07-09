#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,k;
        cin>>n>>k;
        int mul=1;
        int sofar=0;
        int left=n;
        int last=0;
        while(left>0){ 
            last=sofar;
            int old=left;
            if(left%2==0){
                left=left/2;      
            }
            else {left=(left+1)/2;
            
            }
            sofar=sofar+left;
            if(sofar>=k){
                int dou=2*mul;
                int kil=k-last;
                
                ans.push_back((dou*(kil))-mul);
                break;
            }
            mul=mul*2;
            if(old%2==0){
                left=old/2;
                
            }
            else {left=((old)-1)/2;
            
            }
        }
    }
    for(int a:ans)cout<<a<<endl;

}