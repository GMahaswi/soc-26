#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long target;
    if (!(cin >> n >> target)) return 0;

    vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    // Map to store: sum -> list of pairs of 1-based indices
    unordered_map<long long, vector<pair<int, int>>> pair_sums;
    // Reserve memory to reduce hash collisions/rehashes for O(n^2) pairs
    pair_sums.reserve(n * n); 

    // Step 1: Precompute all pair sums and store them
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long current_pair_sum = vec[i] + vec[j];
            pair_sums[current_pair_sum].push_back({i + 1, j + 1});
        }
    }

    // Step 2: Search for complementary pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long current_sum = vec[i] + vec[j];
            long long required_complement = target - current_sum;

            // Check if the complement exists
            auto it = pair_sums.find(required_complement);
            if (it != pair_sums.end()) {
                // Iterate through the pairs that make up the complement
                for (const auto& p : it->second) {
                    // CRITICAL: Ensure all 4 indices are strictly unique physical slots
                    if (p.first != i + 1 && p.first != j + 1 && 
                        p.second != i + 1 && p.second != j + 1) {
                        
                        cout << i + 1 << " " << j + 1 << " " 
                             << p.first << " " << p.second << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}