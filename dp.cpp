#include <bits/stdc++.h>
using namespace std;

int stairclimber(int n, vector<int> &dp) {
	if (n == 0 || n == 1) return 1;//kyuki sirf 2 hi call karega oth stair par to u sko batana h ha ek tareeka h aane ka and 1 par 3 and 2 dono kar sakte h
	if (dp[n] != 0)return dp[n];
	int f1 = stairclimber(n - 1, dp);
	int f2 = stairclimber(n - 2, dp);
	return dp[n] = f1 + f2;
}
int mincostclimber(int n, vector<int> &dp, vector<int> &cost) { //we wanna know nth stair pe pohochne ki cost given the cost of climbing 1 or two steps from 0 to n-1th stair
	if (n == 0 || n == 1) return 0;
	if (dp[n] != 0)return dp[n];
	int f1 = mincostclimber(n - 1, dp, cost) + cost[n - 1]; //n-1th stair tak pohochne ki cost and then tyou hva to pay cost[n-1]to climb 1 or two steps upar
	int f2 = mincostclimber(n - 2, dp, cost) + cost[n - 2];
	return dp[n] = min(f1, f2);
}
class pathf {
public:
	int pathnumberways(int i, int j, vector<vector<int>> &dp) { //q me m*n matrix bolke dete h
		if (i == 0 && j == 0) return 1;
		if (i < 0 || j < 0) return 0;//outta boundary
		if (dp[i][j] != -1)return dp[i][j];
		int left = pathnumberways(i - 1, j, dp);
		int top = pathnumberways(i, j - 1, dp);
		return dp[i][j] = left + top;
	}
public:
	int pathnumberwaysatab(int n, vector<vector<int>> &dptab) { //q me m*n matrix bolke dete h
		for (int i = 1; i <= n - 1; i++) {
			dptab[i][0] = 1;
			dptab[0][i] = 1;
		}
		for (int i = 1; i <= n - 1; i++) {
			for (int j = 1; j <= n - 1; j++) {
				int right = dptab[i - 1][j];
				int bottom = dptab[i][j - 1];
				dptab[i][j] = right + bottom;
			}
		}
		return dptab[n - 1][n - 1];

	}
public:
	int gen(int n) {
		vector<vector<int>> dp(n, vector<int>(n, -1));
		vector<vector<int>> dptab(n, vector<int>(n, 0));
		int noways = pathnumberwaysatab(n, dptab);
		return noways;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	vector<int> cost(n);
	/*for (int i = 0; i < n; i++)cin >> cost[i];
	int ans = mincostclimber(n, dp, cost);
	cout << ans << endl;*/
	pathf ob1;
	int ans2 = ob1.gen(n);
	cout << ans2 << endl;
	//for (int i = 1; i < 5; i++)cout << i << " ";
	return 0;
}
