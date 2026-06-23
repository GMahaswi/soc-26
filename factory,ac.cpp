#include <bits/stdc++.h>
using namespace std;

// Function to check if 't' products can be made in 'mid' seconds
bool isValid(long long mid, const vector<int>& vec, long long t) {
    long long products = 0;
    for (int k : vec) {
        products += (mid / k);
        // Optimization: If we already met or exceeded 't', no need to keep adding
        if (products >= t) return true; 
    }
    return products >= t;
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long t;
    if (!(cin >> n >> t)) return 0;

    vector<int> vec(n);
    int min_machine = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        min_machine = min(min_machine, vec[i]);
    }

    // Binary search range
    // Lower bound: 1 second
    // Upper bound: The fastest machine doing all 't' jobs by itself
    long long low = 1;
    long long high = (long long)min_machine * t;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isValid(mid, vec, t)) {
            ans = mid;        // 'mid' is a valid time, try to find a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;    // Not enough time, increase the search space
        }
    }

    cout << ans << "\n";
    return 0;
}