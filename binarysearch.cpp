#include<bits/stdc++.h>
using namespace std;
int bs(int l, int h, int target, std::vector<int> &a) {
	int mid;
	if (l <= h) { //{0,1,2,3,4,5} call bs(0,5,2)
		int mid = (l + h) / 2;
		if (a[mid] == target)return target;
		if (a[mid] > target) return bs(l, mid - 1, target, a); //notice the use of return statement
		if (a[mid] < target) return bs(mid + 1, h, target, a); //the value you are looking for lies after a[mid] to search space modfy kar uske liye
	}
	return -1;
}
int bsiter(int l, int h, int target, std::vector<int> &a) {
	int mid;
	while (l <= h) { //{0,1,2,3,4,5} call bs(0,5,2)
		int mid = (l + h) / 2;
		if (a[mid] == target)return target;
		if (a[mid] > target) h = mid - 1; //notice the use of return statement
		if (a[mid] < target) l = mid + 1; //the value you are looking for lies after a[mid] to search space modfy kar uske liye
	}
	return -1;
}
int lowerb(int l, int h, int target, vector<int> &a) {
	int mid;
	while (l < h) {
		mid = (l + h) / 2;
		if (a[mid] < target)l = mid + 1;
		else {
			h = mid;
		}
	}
	if (a[l] >= target)return l;
	if (a[h] >= target)return h;
	return -1;
}
int upperb(int l, int h, int target, vector<int> &a) {
	int mid;
	while (l < h) {
		mid = (l + h) / 2;
		if (a[mid] <= target)l = mid + 1;
		else {
			h = mid;
		}
	}
	if (a[l] > target)return l;
	if (a[h] > target)return h;
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	vector<int> a;
	a = {0, 1, 2, 3, 5, 6};
	int ans = a[lowerb(0, 5, 4, a)];
	int ans1 = a[upperb(0, 6, 5, a)];
	cout << ans1;
}
