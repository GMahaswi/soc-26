#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
 
        for(auto &e : a){
            cin >> e;
        }
        int index_maxi =0;
        int index_mini = 0;
        int maxi =INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i] > maxi){
                maxi = a[i];
                index_maxi= i;
            }
            if(a[i] < mini){
                mini = a[i];
                index_mini = i;
            }
        }
        vector<pair<int,int>> v;
 
        if(maxi > -mini){
            for(int i=0;i<n;i++){
                if(i!= index_maxi){
                    a[i] += maxi;
                    v.push_back({i,index_maxi});
                }
            }
            for(int i=1;i<n;i++){
                a[i]  += a[i-1];
                v.push_back({i,i-1});
            }
        }else{
            for(int i=0;i<n;i++){
                if(i!= index_mini){
                    a[i] += mini;
                    v.push_back({i,index_mini});
                }
            }
            for(int i= n-1;i>=1;i--){
                a[i-1] += a[i];
                v.push_back({i-1,i});
            }
        }
 
        cout << v.size()<<"\n";
        for(auto [i,j]:v){
            cout << i+1 << " " << j+1 << "\n";
        }
 
    }
}