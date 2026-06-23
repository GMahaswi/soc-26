#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<pair<int,int>> cur;
    cur.push_back({0,0});

    string ans;
    ans += grid[0][0];
    vector<vector<int>>visited(n,vector<int>(n,-1));
    for (int step = 0; step < 2 * n - 2; step++) {

        char best = 'Z' + 1;

        // Find smallest reachable character
        for (auto [x, y] : cur) {
            if (x + 1 < n)
                best = min(best, grid[x + 1][y]);

            if (y + 1 < n)
                best = min(best, grid[x][y + 1]);
        }

        vector<pair<int,int>> nxt;
        

        // Keep only cells with that character
        for (auto [x, y] : cur) {

            if (x + 1 < n &&
                grid[x + 1][y] == best &&
                visited[x+1][y]!=step) {

                nxt.push_back({x + 1, y});
                visited[x+1][y]=step;
            }

            if (y + 1 < n &&
                grid[x][y + 1] == best &&
                visited[x][y+1]!=step) {

                nxt.push_back({x, y + 1});
                visited[x][y+1]=step;
            }
        }

        ans += best;
        cur.swap(nxt);
    }

    cout << ans << '\n';
    return 0;
}