#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long dfs(int n, vector<long long> &vs) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (vs[n] != -1) return vs[n];
    long long total = 0;
    for (int step = 1; step <= 6; step++) {
        total = (total + dfs(n - step, vs)) % MOD;
    }
    return vs[n] = total;
}
int main() {
    int n; cin>>n;
    vector<long long> vs(n+1, -1);
    cout<<dfs(n, vs);   
}   