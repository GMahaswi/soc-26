/*
You are given an array a1,a2,…,an
. You can perform the following operation on this array at most once:

Choose a positive integer k
, as well as a subsequence b1,b2,…,bm
 of the array a
∗
 and add k
 to each element of this subsequence, that is, for each i
 perform abi:=abi+k
.
You need to determine whether it is possible to sort the array in nondecreasing order by performing this operation at most once.

∗
A sequence b
 is a subsequence of a sequence a
 if b
 can be obtained from a
 by the deletion of several (possibly, zero or all) element from arbitrary positions.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

In the first line of each test case, one integer n
 is given (1≤n≤2⋅105
) — the length of the array a
.

In the second line of each test case, n
 integers a1,a2,…,an
 are given (1≤ai≤109
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print "Yes" if it is possible to sort the array by performing the operation at most once. Otherwise, print "No". You may print the answer in any case. For example, "YeS", "YES", "NO", "nO" will also be accepted
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[vec[i]]++;
        }
        int i=0;
        int min=0;
        bool t=true;
        while(i<n){
            if(i!=0){
                if(vec[i-1]>vec[i]){
                    int cou=0;
                    while(i<n&&vec[i-1]>vec[i]){
                         cou++;
                        mp[i]-=cou;
                        if(mp[i]<=0){
                            cout<<"NO"<<endl;;
                            t=false;
                            break;
                        }
                        else {
                            min=max(min,vec[i-1]-vec[i]);
                        }
                        i++;
                    }
                    vec[i-1]=vec[i-1]+(cou*min);
                }
                else i++;
            }
            else i++;
            if(!t)break;
        }
        if(t)cout<<"YES"<<endl;
    }
}
