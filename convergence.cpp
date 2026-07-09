#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int  n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){cin>>vec[i];}
        sort(vec.begin(),vec.end());
        int median;
        if(n%2==1){
            median=vec[n/2];
            int start=-1;
            int end;
            for(int i=0;i<n;i++){
                if(i==0&&vec[i]==median){
                    start=0;
                }
                else if(vec[i]==median&&vec[i-1]!=median){
                    start=i;
                }
                else if(i==n-1&&vec[i]==median){
                    end=0;
                }
                else if(vec[i]==median&&vec[i+1]!=median){
                    end=n-1-i;
                    break;
                }
            }

            ans.push_back(max(start,end));
        }
        else {
            int bef=n/2-1;
            int h=n/2;
            if(vec[bef]==vec[h]){
                median=vec[h];
                int start=-1;
            int end;
            for(int i=0;i<n;i++){
                if(i==0&&vec[i]==median){
                    start=0;
                }
                else if(vec[i]==median&&vec[i-1]!=median){
                    start=i;
                }
                else if(i==n-1&&vec[i]==median){
                    end=0;
                }
                else if(vec[i]==median&&vec[i+1]!=median){
                    end=n-1-i;
                    break;
                }
            }

            ans.push_back(max(start,end));
            }
            else {
                ans.push_back(n/2);
            }
        }
    }
    for(int a:ans){
        cout<<a<<endl;
    }
}