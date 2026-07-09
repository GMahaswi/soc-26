#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        vector<int>vec(m);
        for(int i=0;i<m;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        vector<int>quer(q);
        for(int i=0;i<q;i++){
            
            cin>>quer[i];
            int d=quer[i];
            auto it=upper_bound(vec.begin(),vec.end(),d);
            int indg=-1;
            if(it!=vec.end())indg=it-vec.begin();
            if(indg==-1){
                int l=vec[m-1];
                ans.push_back(n-l);
            }
            else if(indg==0){
                int f=vec[0];
                ans.push_back(f-1);
            }
            else {
                int f=vec[indg-1];
                int l=vec[indg];
                f=d-f;
                l=l-d;
                int med=(l+f)/2;
                ans.push_back(med);
                
            }
        }
    }
    for(int a:ans)cout<<a<<endl;
}