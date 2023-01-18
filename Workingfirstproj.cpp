#include <bits/stdc++.h>
using namespace std;
/*bool fsum(int i, vector<int> &ds, vector<int> &a, int target) {
	int n = a.size();
	if (target == 0) {
		ans.push_back(ds);
		return true;
	}
	if (i == n) {
		if (target == 0)return true;
		else return false;
	}
	ds.push_back(a[i]);
	if (fsum(i + 1, ds, a, target - a[i])) return true;
	ds.pop_back();
	if (fsum(i + 1, ds, a, target)) return true;
}*/
void combsum(int i, vector<int> &ds, vector<int> &a, int target, vector<vector<int>> &ans) {
	int n = a.size();
	if (target == 0) {
		ans.push_back(ds);
		return ;
	} //prints only 2,3 and not 11111 for array 1,2,3 and target 5
	if (i == n) {
		if (target == 0) {
			ans.push_back(ds);
		}
		return ;
	}
	if (a[i] <= target) {
		ds.push_back(a[i]);
		combsum(i + 1, ds, a, target - a[i], ans);
		ds.pop_back();
	}
	combsum(i + 1, ds, a, target, ans);
}
void generate(int ind, vector<int> &ds, vector<int>& candidates, int target, vector<vector<int>> &ans) {
	if (ind == candidates.size()) {
		if (target == 0)ans.push_back(ds);
		return;
	}

	if (candidates[ind] <= target) {
		ds.push_back(candidates[ind]);
		generate(ind, ds, candidates, target - candidates[ind], ans);
		ds.pop_back();
	}
	generate(ind + 1, ds, candidates, target, ans);

}

void combinationSum(vector<int>& candidates, int target, vector<vector<int>> &ans) {
	vector<int> ds;
	generate(0, ds, candidates, target, ans);

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> candidates = {1, 2, 3};
	vector<int> ds;
	vector<vector<int>> ans;
	combinationSum(candidates, 5, ans);
	for (auto i : ans) {
		for (auto p : i) {
			cout << p << " ";
		}
		cout << endl;
	}
	/*cout << n << endl;
	for (int i = 1; i < 5; i++)cout << i << " ";*/
	return 0;
}
