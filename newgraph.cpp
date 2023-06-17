#include <bits/stdc++.h>
using namespace std;

void kefaparkdfs(int vertex,int catcount,int m, vector<int> g[], vector<int>& cats, vector<bool>& vis,int& res,vector<int>& degree) {
    vis[vertex] = true;
    if(cats[vertex]==1){
        catcount++;
    }
    if(catcount>m)return ;
    //fails for skewed tree
    if(degree[vertex]==1 and vertex!=1){
        if(cats[vertex]==1){
            if(catcount<=m)res++;
        }
        else{
            if(catcount<=m)res++;
        }
        
    }
    for (auto child : g[vertex]) {
        if (vis[child] == true)continue;
        /*if(cats[vertex]==1&& cats[child]==1)kefaparkdfs(child,catcount+1, m, g,cats, vis,res,degree);
        if(cats[vertex]==1&& cats[child]==0)kefaparkdfs(child,0, m, g,cats, vis,res,degree);
        else kefaparkdfs(child,0, m, g,cats, vis,res,degree);*/
        if(cats[vertex]==1&& cats[child]==1)kefaparkdfs(child,catcount, m, g,cats, vis,res,degree);
        else kefaparkdfs(child,0, m, g,cats, vis,res,degree);
    }
    if(cats[vertex]==1){
        catcount--;
    }
}
int main() {
    int n,m;
    cin >> n>>m;
    vector<int> cats(n+1);
    vector<int> g[n+1];
    int res=0;vector<bool> vis(n+1, false);
    for(int i=1;i<=n;i++)cin>>cats[i];
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> degree(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        degree[i] = g[i].size() ;
    }
    int catcount=0;
    kefaparkdfs(1,catcount,m,g,cats,vis,res,degree);
    cout<<res<<endl;
}
