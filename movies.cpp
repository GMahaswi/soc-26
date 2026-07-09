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

        vector<int>movie1(n);
        vector<int>movie2(n);
        for(int i=0;i<n;i++)cin>>movie1[i];
        for(int i=0;i<n;i++)cin>>movie2[i];
        int m1=0;
        int m2=0;
        int pos=0;
        int neg=0;
        for(int i=0;i<n;i++){
            if(movie1[i]!=movie2[i]){
                if(movie1[i]>movie2[i]){
                    m1+=movie1[i];
                }
                else m2+=movie2[i];
            }
            else {
                if(movie1[i]==1)pos++;
                else if(movie1[i]==-1)neg++;
            }
        }
        if(m1>=m2){
            m1=m1-neg;
            m2=m2+pos;
            if(m1>m2){
                ans.push_back(m2);
            }
            else {
                int h=(m1+m2)/2;
                int diff=(m2-m1)/2;
                diff=min(diff,neg+pos);
                m1=m1+diff;
                m2=m2-diff;
                ans.push_back(min(m1,m2));
            }
        }
        else {
            swap(m1,m2);
            m1=m1-neg;
            m2=m2+pos;
            if(m1>m2){
                ans.push_back(m2);
            }
            else {
                int h=(m1+m2)/2;
                int diff=(m2-m1)/2;
                diff=min(diff,neg+pos);
                m1=m1+diff;
                m2=m2-diff;
                ans.push_back(min(m1,m2));
            }
        }
    }
    for(int a:ans)cout<<a<<endl;
}