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
			dp[i][j]=take||notake;//do not put dp[i][target]=take||notake;
		}
	}
	return dp[index][target];
}
void genbinarystringsizek(int i,int k,vector<int>& ds,vector<vector<int>>& ans){
	if(i==k){
		ans.push_back(ds);
		return;
	}
	ds.push_back(0);
	genbinarystringsizek(i+1,k,ds,ans);
	ds.pop_back();
	if(i==0){
		ds.push_back(1);
		genbinarystringsizek(i+1,k,ds,ans);
		ds.pop_back();
	}
	if(i!=0&& ds[i-1]!=1){
		ds.push_back(1);
		genbinarystringsizek(i+1,k,ds,ans);
		ds.pop_back();
	}
}
int main(){
	//vector<int> nums={2,3,1,9,8};
	//vector<vector<int>> dp(5,vector<int>(24,0));
	//targetiterative(4,20,nums,dp);
	//for(int i=1;i<23;i++){
	//	cout<<i<<": "<<dp[4][i]<<endl;
	//}
	vector<int> ds;
	vector<vector<int>> ans;

	genbinarystringsizek(0,2,ds,ans);
	for(auto p:ans){
		for(auto d:p)cout<<d<<" ";
		cout<<endl;
	}
	return 0;
}
/*struct Item {
    int value, weight;
    Item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}


double fractionalKnapsack(int W, struct Item arr[], int N){
    sort(arr, arr + N, cmp);
    double finalvalue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }
        else {
            finalvalue
                += arr[i].value
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}*/