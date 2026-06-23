#include<iostream>
#include<vector>
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
    long long t;
    cin >> t;
    while(t--){
        int c;
        int d;
        cin>>c>>d;
        if(((2*c)-d)%3==0&&((2*d)-c)%3==0&&(2*d)-c>=0&&(2*c)-d>=0){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }

}