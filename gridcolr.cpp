#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map<char,int>m;
            m[v[i][j]]++;
            if(i>0)m[v[i-1][j]]++;
            if(j>0)m[v[i][j-1]]++;
            m['A']++;
            if(m['A']==1){
                v[i][j]='A';
                continue;
            }
            m['B']++;
            if(m['B']==1){
                v[i][j]='B';
                continue;
            }
            m['C']++;
            if(m['C']==1){
                v[i][j]='C';
                continue;
            }
            m['D']++;
            if(m['D']==1){
                v[i][j]='D';
                continue;
            }
        }
    }
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
}