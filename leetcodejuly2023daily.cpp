#include <bits/stdc++.h>
using namespace std;
bool targetdprecur(int i,int target,vector<int>& nums,vector<vector<int>>& dp ){
	if(i==0){
		return (target==nums[0]);
	}
	if(target==0)return true;
	if (dp[i][target] != -1) {
        return dp[i][target];
    }
	bool notake=targetdprecur(i-1,target,nums,dp);
	bool take=false;
	if(nums[i]<=target){
		take=targetdprecur(i-1,target-nums[i],nums,dp);
	}
	return dp[i][target]=take||notake;
}
bool targetiterative(int index,int target,vector<int>& nums,vector<vector<int>>& dp ){
	int n=nums.size();
	if(nums[0]<=target)dp[0][nums[0]]=true;
	for(int i=0;i<=n-1;i++){
		dp[i][0]=true;
	}
	for(int i=1;i<=nums.size()-1;i++){
		for(int j=1;j<=target;j++){
			bool notake=dp[i-1][j];
			bool take=false;
			if(nums[i]<=j){
				take=dp[i-1][j-nums[i]];
			}
			dp[i][j]=take||notake;
		}
	}
	return dp[index][target];
}
int main(){
	vector<int> nums={2,3,1,9,8};
	vector<vector<int>> dp(5,vector<int>(24,0));
	targetiterative(4,20,nums,dp);
	for(int i=1;i<23;i++){
		cout<<i<<": "<<dp[4][i]<<endl;
	}
	return 0;
}