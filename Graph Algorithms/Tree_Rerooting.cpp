#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAX = 2e6 + 15;
 
ll n, dp[MAX], sub[MAX], ans[MAX];
vector<ll> adj[MAX];
 
void dfs(ll u, ll p){
	sub[u] = 1;
	
	for(auto v : adj[u]){
		if(v == p) continue;
		dfs(v, u);
		
		dp[u] += (dp[v] + sub[v]);
		sub[u] += sub[v];
	}
}
 
void girar(ll u, ll p){
	ans[u] = dp[u];
	
	for(auto v : adj[u]){
		if(v == p) continue;
		ll dpu = dp[u], subu = sub[u];
		ll dpv = dp[v], subv = sub[v];
		
		dp[u] -= (dp[v] + sub[v]);
		sub[u] -= sub[v];
		
		dp[v] += (dp[u] + sub[u]);
		sub[v] += sub[u];
		
		girar(v, u);
		
		dp[u] = dpu, dp[v] = dpv;
		sub[u] = subu, sub[v] = subv;
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 1; i < n; i++){
		ll u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, -1);
	
	girar(1, -1);
	
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	
	return 0;
}
