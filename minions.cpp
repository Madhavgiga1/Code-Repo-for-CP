#include<bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
int f(int mid, vector<int> a, int h) {
	int i = 0; int n = a.size();
	while (i <= n - 1 && h > 0) {
		if (a[i]) <= mid{
			h--;
			a[i] = 0;
			i++;
		}
		else {
			a[i] = a[i] - mid;
			h--;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, h;
		cin >> n >> h;
		vector<int>a(n);
		int highest = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum = sum + a[i];
			highest = max(a[i], highest);
		}
		int l = 1, h = highest, mid;
		while (h - l > 1) {
			mid = (l + h) / 2;
			if (f(mid)) {
				h = mid;
			}
			else {
				l = mid + 1;
			}
		}

	}
	return 0;
}
