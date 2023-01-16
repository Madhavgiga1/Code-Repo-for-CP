#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//alocate space in heap for a structure of type node and store the addres returned by new node in a pointer,all pointers have address stored
vector<vector<int>> lot(TreeNode *root) {
	vector<vector<int>> leveltrav;
	if (root == NULL)return leveltrav;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		vector<int> elementsinthelevel;
		for (int i = 0; i < size; i++) {
			TreeNode* noder = q.front(); q.pop();
			elementsinthelevel.push_back(noder->val);
			if (noder->left != NULL)q.push(noder->left);
			if (noder->right != NULL)q.push(noder->right);
		}
	}
	return leveltrav;
}

vector<int> preordertrav(TreeNode *root) {
	vector<int>preorder;
	stack<TreeNode *>st; if (root == MULL)return preorder;
	st.push(root);
	while (!st.empty()) {
		TreeNode *noder = st.top();
		st.pop();
		preorder.push_back(noder->val);
		if (noder->right != NULL)st.push(noder->right);
		if (noder->left != NULL)st.push(noder->left);
	}
	return preorder;
}

vector<int> inordertrav(TreeNode *root) {
	vector<int>inorder;
	stack<TreeNode *>st;
	TreeNode* noder = root;
	//if(root==MULL)return inorder;
	//st.push(root);
	while (true) {
		if (noder != NULL) {
			st.push(noder);
			noder = noder->left;
		}
		else {
			if (st.empty())break;
			noder = st.top();
			st.pop();
			inorder.push_back(noder->val);
			noder = noder->right;
		}

	}
	return inorder;
}


class Solution {
public:
	vector<int> f(TreeNode* root) {
		vector<int> answer;
		if (root == NULL)return answer;
		queue<TreeNode*> q; q.push(root);
		while (!q.empty()) {
			int size = q.size();
			int maxi = INT_MIN;
			for (int i = 0; i < size; i++) {
				TreeNode *noder = q.front(); q.pop();
				if (noder->left != NULL)q.push(noder->left);
				if (noder->right != NULL)q.push(noder->right);
				maxi = max(maxi, noder->val);
			}
			answer.push_back(maxi);
		}
		return answer;
	}
	vector<int> largestValues(TreeNode* root) {
		vector<int> answer = f(root);
		return answer;
	}
};
class Solution {
public:
	int height(TreeNode *root, int &diameter) {
		if (root == NULL)return 0;
		int lh = height(root->left, diameter);
		int rh = height(root->right, diameter);
		diameter = max(diameter, lh + rh);
		return 1 + max(lh, rh);
	}
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = 0;
		f(root, diameter);
		return diameter;
	}
};
class Solution {
public:
	int height(TreeNode *root) {
		if (root == NULL)return 0;
		int lh = height(root->left);
		if (lh == -1)return -1;
		int rh = height(root->right);
		if (rh == -1)return -1;
		if (abs(lh - rh) > 1)return -1;
		return 1 + max(lh, rh);
	}
	bool isBalanced(TreeNode* root) {
		return height(root) != -1
	}
};
class Solution {
public:
	int f(TreeNode* root, int &maxi) {
		if (root == NULL)return 0;
		int ls = f(root->left);
		int rs = f(root->right);
		maxi = max(maxi, (root->val + ls + rs));
		return root->val + max(ls, rs);
	}
	int maxPathSum(TreeNode* root) {
		int answer = INT_MIN;
		f(root, answer);
		return answer;
	}
};
class Solution {
public:
	string categorizeBox(int length, int width, int height, int mass) {
		bool bulky = false; bool heavy = false;
		long long l = length; long long w = width; long long h = height; long long m = mass;
		long long volume = l * w * h;
		if (l >= 1e4 || w >= 1e4 || h >= 1e4 || m >= 1e4 || ((volume) >= 1e9) ) {
			bulky = true;
		}
		if (mass >= 100)heavy = true;
		string answer = "";
		if (bulky && heavy)answer = "Both";
		else if (!bulky && !heavy ) answer = "Neither";
		else if (bulky && !heavy) answer = "Bulky";
		else if (!bulky && heavy ) answer = "Heavy";
		return answer;

	}
};
class boundarytrav {

	struct node {
		int data;
		struct node * left, * right;
	};

	bool isLeaf(node * root) {
		if (root -> left == NULL && root -> right == NULL)return true;
		return false;
	}

	void addLeftBoundary(node * root, vector < int > & res) {
		node * cur = root -> left;
		while (cur) {
			if (isLeaf(cur) == false) res.push_back(cur -> data);
			if (cur -> left != nullptr) cur = cur -> left;
			else cur = cur -> right;
		}
	}
	void addRightBoundary(node * root, vector < int > & res) {
		node * cur = root -> right;
		vector < int > tmp;
		while (cur) {
			if (!isLeaf(cur)) tmp.push_back(cur -> data);
			if (cur -> right) cur = cur -> right;
			else cur = cur -> left;
		}
		for (int i = tmp.size() - 1; i >= 0; --i) {
			res.push_back(tmp[i]);
		}
	}

	void addLeaves(node * root, vector < int > & res) {
		if (isLeaf(root)) {
			res.push_back(root -> data);
			return;
		}
		if (root -> left != NULL) addLeaves(root -> left, res);
		if (root -> right != NULL) addLeaves(root -> right, res);
	}

	vector < int > printBoundary(node * root) {
		vector < int > res;
		if (root == NUll) return res;
		if ( isLeaf(root) == false) res.push_back(root -> data);

		addLeftBoundary(root, res);

		// add leaf nodes
		addLeaves(root, res);

		addRightBoundary(root, res);

		return res;
	}

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	return 0;
}
