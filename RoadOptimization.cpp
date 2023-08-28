#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll modulo = 1e9 + 7;
const int N=501;
//int dp[N][N];

/*int f(int i,int k,int last,vector<int>& d){
	if (i == 0) {
        return (d[last] - d[0]) * a[0];
    }
    if(dp[i][k]!=-1)return dp[i][k];
	int take=(d[last]-d[i])*a[i]+f(i-1,k,i,d);
	int notake=INT_MAX;
	if (k > 0) {
		//notake=1e9;
		for(int l=i+1;l<=n-1;l++){
			int su=f(i-1,k-1,l,d)+(d[l]-d[i-1])*a[i-1];
			notake=min(notake,su);
		}
	    
	}


	return dp[i][k]=min(take,notake);

}*/
void solve(){
	ll n,l,k;
	cin>>n>>l>>k;
	ll a[501];
	ll d[501];
    for(int i=0;i<n;i++)cin>>d[i];
    d[n]=l;
 
    for(int i=0;i<n;i++)cin>>a[i];
 
    vector<vector<ll>>dp(n+1,vector<ll>(k+1,1e12));

	dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+(d[i]-d[i-1])*a[i-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(i<=j)continue;
 
            for(int u=i-1;u>=0;u--){
                if(j<i-u-1)break;
                dp[i][j]=min(dp[i][j],dp[u][j-(i-u-1)]+(d[i]-d[u])*a[u]);
            }
        }
    }
	ll ans=1e13;
	for(int i=0;i<=k;i++){
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	
        	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
    return 0;
}