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
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());  
        bool corect=true;
       
      
        int last=vec[1];
        int sl=vec[0];
        for(int i=2;i<n;i++){
            int val=(sl%last);
            if(val!=vec[i]){
                corect=false;
                break;
            }
            sl=vec[i-1];
            last=vec[i];
        }
            if(corect){
            cout<<vec[0]<<" "<<vec[1]<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
}