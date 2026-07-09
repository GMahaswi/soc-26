#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<vector<int>>ans(t);
    for (int j=0;j<t;j++){
        int  n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){cin>>vec[i];}
        int carry=0;
        int min=0;
    
        for(int i=0;i<n;i++){
            vec[i]=vec[i]+carry;
            carry=0;
           
            if(i==0){
                ans[j].push_back(vec[i]);
                min=vec[i];
            }
            else if(min>=vec[i]){
                min=((i*min)+(vec[i]))/(i+1);
                carry=((i*min)+(vec[i]))%(i+1);
                ans[j].push_back(min);
               
            }
            else if (min<vec[i]){
                carry=vec[i]-min;
                ans[j].push_back(min);
            }
        }
    }
    for(int i=0;i<t;i++){
    for(int a:ans[i]){
        cout<<a<<" ";
    }
    cout<<endl;
}
}