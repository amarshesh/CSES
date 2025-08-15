// #include <bits/stdc++.h>
// using namespace std;

// int dfs(vector<vector<int>> &adj, int node, vector<bool> &visited) {
//     visited[node] = true;
//     int maxi = 0;
//     for (auto neighbor : adj[node]) {
//         if (!visited[neighbor]) {
//             int depth = 1 + dfs(adj, neighbor, visited);
//             maxi = max(maxi, depth);
//         }
//     }
//     return maxi;
// }

// int main() {
//         int n;
//         cin >> n;
//         vector<vector<int>> adj(n);
//         for (int i = 0; i < n - 1; i++) {
//             int u, v;
//             cin >> u >> v;
//             u--; v--;   
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         for (int i = 0; i < n; i++) {
//             vector<bool> visited(n, false);
//             cout << dfs(adj, i, visited) << " ";
//         }
//         cout << endl;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums1(n + 2);
    vector<int> nums2(n);

    for (int i = 0; i < n + 2; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];

    int ans = INT_MAX;

    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            vector<int> temp;
            for (int k = 0; k < n + 2; k++) {
                if (k == i || k == j) continue;
                temp.push_back(nums1[k]);
            }

            unordered_set<int> diffs;

            for (int k = 0; k < n; k++) {
                diffs.insert(nums2[k] - temp[k]);
            }

            if (diffs.size() == 1) {
                ans = min(ans, *diffs.begin());
            }
        }
    }

    cout << ans << endl;
    return 0;
}
