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
	 	  ll N, K;
		  cin >>N>> K;
		  map<ll, ll> frequency;
		  for (ll i = 0; i < N; i++) {
			  	ll it;cin>>it;
			  	frequency[it]++;
		  }
		  vector<ll> arr;
		  for (auto p : frequency) {
		    	arr.push_back(p.first);
		  }	  
		  N = arr.size();
		  K=min(K,N);

		  vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
		  for(ll i=0;i<=N;i++){
		  	dp[i][0]=1;
		  }

		  for (ll i = 1; i <= N; i++) {
		    for (ll j = 1; j <= K; j++) {
		    	ll notake=dp[i-1][j];
		    	ll take=(dp[i - 1][j-1]*frequency[arr[i-1]]) %modulo;
		    	// we put i-1 becuase array is only 0 based no
		        dp[i][j] =take + notake ;
		        dp[i][j]%=modulo;
		    }
		  }
		  ll ans = 0;
		  for (ll i = 0; i <= K; i++) {
		   		ans+=dp[N][i];
		   		ans%=modulo;
		  }
	      cout << ans << endl;	  
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
    return 0;
}