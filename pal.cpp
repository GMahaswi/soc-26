#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
 using namespace std;
// int helper(int i,int t,int n){
//     if(t == 0) return 1;
//     if(i == n+1) return 0;
//     int take=0;
//     if(t-i>=0) take=helper(i+1,t-i,n);
//     int notake=helper(i+1,t,n);
//     return take || notake;
// }
int main(){
    string s;
    cin>>s;
   
    map<char,int>m;
    for(char c:s){
        m[c]++;
    }
    int odd=0;
    char od;
    for(auto p:m){
        if(p.second%2!=0&&odd==1){
            cout<<"NO SOLUTION";
            return 0;
        }
        if(p.second%2!=0){odd++;
        od=p.first;
        }
    }
    string n="";
    for(auto p:m){
        if(odd){
            if(p.first==od){
                continue;
            }
            int h=p.second/2;
            while(h--){
                n+=p.first;
            }
        }
        else{
            int h=p.second/2;
            while(h--){
                n+=p.first;
            }
        }
    }
    if(odd){
        int h=m[od]/2;
            while(h--){
                n+=od;
            }
    }
        string rev = n;
    reverse(rev.begin(), rev.end());
    if(odd){
        n+=od;
    }
    n+=rev;
    cout<<n;


}