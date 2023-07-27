#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool comparePair(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first != p2.first) {
        return p1.first > p2.first; 
    }
    return p1.second < p2.second; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> order;

        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++) {
            int attempts = a[i] % x;
            ans.push_back({attempts, i});
        }

        sort(ans.begin(), ans.end(), comparePair); 

        for (auto p : ans) {
            cout << p.second << " ";
        }
        cout << endl;
    }
    return 0;
}
