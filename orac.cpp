#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll modulo = 1e9 + 7;
#define pb push_back
typedef map<ll,ll> mll;
typedef vector<ll> vll;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
#define all(x) x.begin(),x.end()
#define fl(i,n) for(int i=0;i<n;i++)

void solve(){
	int n,c;
	cin>>n>>c;
	std::vector<int> a(n-1);std::vector<int> b(n-1);
	//std::vector<int> dp(n);
	
	for (int i = 0; i < n-1; ++i){
		cin>>a[i];	
	}
	for (int i = 0; i < n-1; ++i){
		cin>>b[i];	
	}
	int last=0;
	vector<vector<int>> dp(n, vector<int>(2, 1e9));
	dp[0][0] = 0, dp[0][1] = c;
	for (int i = 1; i <= n - 1; ++i) {
		dp[i][0] = min(dp[i][0], dp[i-1][1] + a[i-1]);
		dp[i][0] = min(dp[i][0], dp[i-1][0] + a[i-1]);
		dp[i][1] = min(dp[i][1], dp[i-1][1] + b[i-1]);
		dp[i][1] = min(dp[i][1], dp[i-1][0] + b[i-1] + c);
	}
	
	
	for(int i=0;i<=n-1;i++){
		cout<<min(dp[i][0],dp[i][1])<<" ";
	}
	cout<<endl;
	
        	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
    return 0;
}