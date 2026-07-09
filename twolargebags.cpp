#include<bits/stdc++.h>
using namespace std;
#define int long long
bool func(){
    int n;
    cin>>n;
    vector<int>vec(n);
    vector<int>nums(1002,0);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        nums[vec[i]]++;
    }
    for(int i=1;i<=1000;i++){
        
        
        if(nums[i]%2==1){
            if(nums[i]<2)return false;
            nums[i+1]++;   
            
        }
        if(nums[i]>=4){
            int d=(nums[i]-2)/2;
                nums[i+1]+=(d*2);
            }
    }
    if(nums[1001]%2!=0){
        return false;
    }

    return true;
}
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        if(func()){
            ans.push_back(1);
        }
        else ans.push_back(0);
    }
    for(int a:ans){
        if(a)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}