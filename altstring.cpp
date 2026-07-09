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
        string s;
        cin>>s;
        if(n%2==1){
            
            vector<vector<int>>prefix(2,vector<int>(26,0));
            vector<vector<int>>suffix(2,vector<int>(26,0));
            

            for(int i=0;i<n;i++){
                suffix[i%2][s[i]-'a']++;
            }
            int min_ops = INT_MAX;
        // Initialize pref arrays to 0, suff arrays with full string counts
        
        for (int i = 0; i < n; i++) {
            // 1. Remove s[i] from suff
            suffix[i % 2][s[i]-'a']--;
            
            // 2. Calculate max frequency if we delete i
            int max_even = 0, max_odd = 0;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                max_even = max(max_even, prefix[0][ch-'a'] + suffix[1][ch-'a']);
                max_odd = max(max_odd, prefix[1][ch-'a'] + suffix[0][ch-'a']);
            }
            
            int current_ops = 1 + (((n - 1) / 2) - max_even) + (((n - 1) / 2) - max_odd);
            min_ops = min(min_ops, current_ops);
            
            // 3. Add s[i] to pref before moving to next index
            prefix[i % 2][s[i]-'a']++;
            
        }
        ans.push_back(min_ops);
    }
        else{
            int a=0;
            int h=(n/2);
            map<char,int>mp1;
            map<char,int>mp2;
            for(int i=0;i<h;i++){
                int m=(2*i);
                mp1[s[m]]++;
                mp2[s[m+1]]++;
            }
            int mxeven=0;
            char even;

            for(auto p:mp1){
                if(mxeven<p.second){even=p.first;mxeven=p.second;}
            }
            a+=(h-mp1[even]);
            int mxodd=0;
            char odd;

            for(auto p:mp2){
                if(mxodd<p.second){odd=p.first;mxodd=p.second;}
            }
            a+=(h-mp2[odd]);
            ans.push_back(a);
        }
    }
    for(int a:ans)cout<<a<<endl;
}