#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;
        int div=(y/x);
        int count=0;
        while(count<k ){
            if(x<y){
                int left=k-count;
                if(left<(y-x)){
                    x=x+(left);
                    break;
                }
                left=left-(y-x);
                x=1+(left%(y-1));
                break;
            }
            int div=x/y;
            int diff=(((div+1)*y)-x);
            if(x%y==0)x=x+1;
            else if(diff>(k-count)){x=x+(k-count);break;}
            else {
                count=count+diff-1;
                x=x+(diff);
            }
            
            while(x%y==0){
                x=(x/y);
            }
            count++;
        }
        ans.push_back(x);
    }
    for(auto a:ans)cout<<a<<endl;
}