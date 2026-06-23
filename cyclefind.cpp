#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int l=s.length();
        if(l<=10){
            cout<<s<<endl;
        }
        else {
            string in=to_string(l-2);
            in=in+s.substr(l-1,1);
            in=s.substr(0,1)+in;
            cout<<in<<endl;
        }
    }

}
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj.push_back({a-1,b-1,c});
        
    }
    vector<int>parent(n,-1);
    for(int i = 0; i < n; i++) parent[i] = i;
    vector<int>dist(n,0);
    int cyclenode=-1;
    for(int i=1;i<=n;i++){
        cyclenode=-1;
        for(auto p:adj){
            if(dist[p[1]]>dist[p[0]]+p[2]){
                parent[p[1]]=p[0];
                dist[p[1]]=dist[p[0]]+p[2];
                cyclenode=p[1];
            }
        }
    }
    if(cyclenode==-1){
        cout<<"NO";
        return 0;
    }
    else {
        cout<<"YES"<<endl;
    }
    int curr = cyclenode;
        for (int i = 0; i < n; i++) {
            curr = parent[curr];
        }
    vector<int> cycle;
        int v = curr;
        while (true) {
            cycle.push_back(v + 1); // +1 to convert back to 1-indexed output
            if (v == curr && cycle.size() > 1) {
                break;
            }
            v = parent[v];
        }

        // Step C: The cycle was collected backwards, flip it!
        reverse(cycle.begin(), cycle.end());

        // Print result
        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] <<" ";
        }
}