
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int one=0;
        int two=0;
        int zer=0;
        for(int i=0;i<n;i++){
            if(v[i]%3==0)zer++;
            else if(v[i]%3==1){
                one++;
            }else{
                two++;
            }
        }
        int ans=0;
        int r1=one%3;

        ans=ans+(zer);
        if(one==two)ans=ans+one;
        else if (one<two)
        {
            ans=ans+one+((two-one)/3);
        }
        else {
            ans=ans+two+((one-two)/3);
        }
        
        cout<<ans<<endl;
    }
}