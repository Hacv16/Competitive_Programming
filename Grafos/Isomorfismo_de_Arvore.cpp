#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAX = 2e6 + 15;
const int INF = 0x3f3f3f3f;
 
int n, id, pai[MAX][2], mx, idx;
vector<int> adj[MAX][2];
map<vector<int>, int> t;
 
int dfs(int u, int tid, int p){
	vector<int> aux;
 
	for(auto v : adj[u][tid]){
		if(v == p) continue;
		aux.emplace_back(dfs(v, tid, u));
	}
 
	sort(aux.begin(), aux.end());
 
	if(t[aux] == 0) t[aux] = ++id;
	return t[aux];
}
 
void dfsd(int u, int p, int d, int tid, bool f){
	if(d >= mx) idx = u, mx = d;
	if(f) pai[u][tid] = p;
 
	for(auto v : adj[u][tid]){
		if(v == p) continue;
		dfsd(v, u, d + 1, tid, f);
	}
}
 
vector<int> getCenters(int tid){
	mx = 0, idx = 0;
	dfsd(1, -1, 0, tid, 0);
	dfsd(idx, -1, 0, tid, 1);
 
	vector<int> path, centers;
 
	int cur = idx;
 
	while(cur != -1){
		path.emplace_back(cur);
		cur = pai[cur][tid];
	}
 
	int diam = path.size();
 
	if(diam % 2) centers.push_back(path[diam / 2]);
	else{ centers.push_back(path[diam / 2]); centers.push_back(path[diam / 2 - 1]); }
 
	return centers;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int tc; cin >> tc;
 
	while(tc--){
		cin >> n;
 
		for(int i = 1; i < n; i++){
			int u, v; cin >> u >> v;
			adj[u][0].emplace_back(v);
			adj[v][0].emplace_back(u);
		}
 
		for(int i = 1; i < n; i++){
			int u, v; cin >> u >> v;
			adj[u][1].emplace_back(v);
			adj[v][1].emplace_back(u);
		}
 
		vector<int> c0 = getCenters(0), c1 = getCenters(1); 
 
		bool ans = false;
 
		int tree1 = dfs(c0[0], 0, -1);
 
		for(auto x : c1)
			if(dfs(x, 1, -1) == tree1) ans = true;
 
		cout << (ans ? "YES" : "NO") << '\n';
 
		for(int i = 1; i <= n; i++)
			adj[i][0].clear(), adj[i][1].clear();
 
		t.clear(); id = 0;
	}
 
	exit(0);
}
