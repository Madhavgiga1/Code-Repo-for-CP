#inclde<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> g[n+1];
	vector<int> color(n+1);
	for(int i=0;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		cin>>color[i];
	}
}