#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    vector<long long>people(n);
    vector<long long>apars(m);
    for(long long i=0;i<n;i++){
        cin>>people[i];
    }
    for(long long i=0;i<m;i++){
        cin>>apars[i];
    }
    sort(people.begin(),people.end());
    sort(apars.begin(),apars.end());
    long long p=0;
    long long a=0;
    long long ans=0;
    while(p<n&&a<m){
        if(abs(apars[a]-people[p])<=k){
            ans++;
            p++;
            a++;
        }
        else{
            if(apars[a]<people[p]){
                a++;
            }
            else{
                p++;
            }
        }
    }
    cout<<ans;
}