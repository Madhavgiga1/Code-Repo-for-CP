#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> nextgreater(){
	int n;cin>>n;vector<int> a(n);
	vector<int> ng(n);ng[n-1]=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int i=n-2;stack<int> st;
	st.push(a[n-1]);
	/*while(i>=0){
		if(st.top()<a[i] && !st.empty()){
			st.pop();
		}
		else{
			ng[i]=st.top();
			st.push(a[i]);
			i--;

		}
	}*/
	for(int i=n-2;i>=0;i--){
		while(st.size() >0 && a[i]>=st.top()){
			st.pop();
		}
		if(st.size()==0){
			ng[i]=-1;
		}
		else{
			ng[i]=st.top();
		}
		st.push(a[i]);
	}
	return ng;
}
vector<int> ngl(){
	int n;cin>>n;
	vector<int> a(n);
	vector<int> ng(n);ng[0]=-1;
	stack<int>st;

	for(int i=0;i<n;i++){cin>>a[i];}
	st.push(a[0]);//i put it before taking nput for the array
	for(int i=1;i<=n-1;i++ ){
		while(a[i]>st.top()&& !st.empty()){
			st.pop();
		}
		ng[i] = st.empty() ? -1 : st.top();
		st.push(a[i]);//forgot this tep

	}
	return ng;
}
vector<int> nsr(){
	int n;cin>>n;
	vector<int> a(n);
	vector<int> ng(n);ng[0]=-1;
	stack<int>st;

	for(int i=0;i<n;i++){cin>>a[i];}
	st.push(a[0]);//i put it before taking nput for the array
	for(int i=1;i<=n-1;i++ ){
		while(a[i]>st.top()&& !st.empty()){
			st.pop();
		}
		ng[i] = st.empty() ? -1 : st.top();
		st.push(a[i]);//forgot this tep

	}
	return ng;
}
class Solution {
public:
    vector<int> nearestSmallerRight(vector<int> &a) {
        int n = a.size();
        stack<int> st;
        st.push(n - 1);
        vector<int> ns(n);
        ns[n - 1] = n-1;
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && a[i] < a[st.top()]) {
                st.pop();
            }
            ns[i] = (st.empty())? n-1 : st.top()-1;
            st.push(i);
        }
        return ns;
    }

    vector<int> nearestSmallerLeft(vector<int> &a) {
        int n = a.size();
        stack<int> st;
        st.push(0);
        vector<int> ns(n);
        ns[0] = 0;
        for (int i = 1; i < n; i++) {
            while (!st.empty() && a[i] < a[st.top()]) {
                st.pop();
            }
            ns[i] = (st.empty())? 0 : st.top()+1;
            st.push(i);
        }
        return ns;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr = nearestSmallerRight(heights);
        vector<int> nsl = nearestSmallerLeft(heights);
        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            maxArea = max(maxArea, heights[i] * (nsr[i] - nsl[i] + 1));
        }
        return maxArea;
    }
};
int main() {

	vector<int> ng=ngl();
	for(auto p:ng)cout<<p<<" ";

	return 0;
}