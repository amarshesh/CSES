#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;

    vector<long long> elements(n);
    elements[0] = x;
    for (int i = 1; i < n; i++) {
        elements[i] = (a * elements[i - 1] + b) % c;
    }

    set<pair<long long ,long long>> st;
    for (int i = 0; i < k; i++) {
        st.insert({elements[i], i});
    }
    int XoredEle = st.begin()->first;
    for (int j = k; j < n; j++) {
        st.erase({elements[j - k], j - k});
        st.insert({elements[j], j});
        XoredEle ^= st.begin()->first;
    }
    cout << XoredEle << "\n";
}
