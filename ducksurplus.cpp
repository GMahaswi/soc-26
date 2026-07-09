#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int s=0;
        while(s<n){
            int st=s;
            int sum=vec[st];
            int last=vec[s];
            while(s+1<n&&vec[s+1]<last){
                s++;
                last=vec[s];
                sum+=last;
            }
            if(s==st)s++;
            else {
                vec[s]=sum;
            }
        }
        return vec[n-1];

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