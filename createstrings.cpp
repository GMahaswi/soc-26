#include<bits/stdc++.h>
using namespace std;
int a;
unordered_map<string,int>m;
vector<string> func(string s,int n){
    vector<string>ans;
    if(n==1){
        ans.push_back(s);
        return ans;
    }
    char f=s[0];
    string s1=s.substr(1);
    vector<string> a1=func(s1,n-1);
    for(string str:a1){
        if(f!=str[0]){
            string news;
            news=f+str;
            
            m[news]++;
            if(m[news]==1)
            ans.push_back(news);
        }
        for(int i=0;i<n-1;i++){
            string news;
            if(f==str[i]){
                while(i+1<n-1&&str[i+1]==f){
                    i++;
                }
                news=str.substr(0,i+1)+f+str.substr(i+1);
            }
            else{
                news=str.substr(0,i+1)+f+str.substr(i+1);
            }
            m[news]++;
            if(m[news]!=1)continue;
            ans.push_back(news);
        }

    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<string>ans=func(s,n);
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(string st:ans){
        cout<<st<<endl;
    }

}