#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
void sieve(vector<bool> &isPrime, vector<int>& lp, vector<int>& hp) { //O(log(logn)) TC
	for (int i = 2; i <= sqrt(N); i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j < N; j = j + i) {
				isPrime[j] = false;
				hp[j] = i;
				if (lp[j] == 0)lp[j] = i;
			}
		}
	}
}

vector<int> primefactorisation(int num, vector<bool> &isPrime, vector<int>& lp, vector<int>& hp) {
	vector<int> prime_factors;

	while (num > 1) {
		int prime_factor = hp[num];
		while (num % prime_factor == 0) {
			prime_factors.push_back(prime_factor);
			num = num / prime_factor;
		}
	}
	return prime_factors;
}
vector<int> divisorsieve() {
	vector<int> divisors[1e5];
	for (int i = 2; i < 1e5; i++) {
		for (int j = i; j < 1e5; j = j + i) {
			divisors[j].push_back(i);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	vector<bool> isPrime(N, 1);
	isPrime[0] = false; isPrime[1] = false;
	vector<int> lp(N); vector<int> hp(N);
	sieve(isPrime, lp, hp);
	int ten = lp[10];
	return 0;


}
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int diameter() {
	int diameter = 0;
	f(diameter, root);
}
int f(int &diameter, TreeNode* root) {
	if (root == NULL)return 0;
	int lh = f(diameter, root->left);
	int rh = f(diameter, root->right);
	diameter = max(diameter, rh + lh);
	return 1 + (max(lh, rh));
}
