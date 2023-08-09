#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;



int minimumcoins(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}

int main(int argc, char const *argv[]){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n,target;
	cin>>n>>target;
	std::vector<int> coins(n);
	for (int i = 0; i < n; ++i){
		cin>>coins[i];
	}
	vector<vector<int>> dp(n,vector<int>(target+1,-1));
	int ans=minimumcoins(coins,target);
	cout<<ans<<endl;
	return 0;
}