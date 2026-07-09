#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        vector<int>b(n);
        for(int i=0;i<n;i++)cin>>b[i];

        int d=b[0]-vec[0];
        int swaps=0;
        for(int i=0;i<n;i++){
            int ser=b[i];
            int find=-1;
            for(int j=i;j<n;j++){
                if(vec[j]<=ser){
                    find=j;
                    break;
                }
            }
            if(find==-1)return -1;
            for(int k=find-1;k>=i;k--){
               
                swaps++;
                swap(vec[k],vec[k+1]);
            }
        }

        return swaps;

}
int32_t main(){
    int t;
    cin>>t;
    
    vector<int>as;
    while(t--){
        as.push_back(func());
    }
    for(int a:as)cout<<a<<'\n';
    return 0;
}