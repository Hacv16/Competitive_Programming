#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int n, q;
int seg[4 * MAX], lz[4 * MAX];
int head[MAX], sub[MAX], tin[MAX], pai[MAX], timer;

vector<int> adj[MAX];

void dfsInit(int u, int p){
	pai[u] = p; sub[u] = 1;
 
	for(auto &v : adj[u]){
		if(v == p) continue;
		dfsInit(v, u);	
 
		sub[u] += sub[v];
 
		if(adj[u][0] == p || sub[v] > sub[ adj[u][0] ])
			swap(v, adj[u][0]);
	}
}
 
void decompose(int u, int chainHead){
	head[u] = chainHead; 
	tin[u] = ++timer;

	if(adj[u].empty()) return;
    int heavy = adj[u][0];

    if(heavy != pai[u])
    	decompose(heavy, chainHead);
        
	for(auto light : adj[u]){
	    if(light == pai[u] || light == heavy) continue;
	    decompose(light, light);
	}
}

void refresh(int p, int l, int r){
	if(lz[p] == 0) return;

	int add = lz[p]; lz[p] = 0;
	seg[p] += (r - l + 1) * add;

	if(l == r) return;

	int e = 2 * p, d = e + 1;

	lz[e] += add;
	lz[d] += add; 
}

void update(int a, int b, int x, int p, int l, int r){
	refresh(p, l, r);

	if(a > r || b < l) return;
	if(a <= l && r <= b){
		lz[p] += x;
		refresh(p, l, r);
		return;
	}

	int m = (l + r) >> 1, e = 2 * p, d = e + 1;
	update(a, b, x, e, l, m); update(a, b, x, d, m + 1, r);

	seg[p] = seg[e] + seg[d];
}

int query(int a, int b, int p, int l, int r){
	refresh(p, l, r);

	if(a > r || b < l) return 0;
	if(a <= l && r <= b) return seg[p];

	int m = (l + r) >> 1, e = 2 * p, d = e + 1;
	return query(a, b, e, l, m) + query(a, b, d, m + 1, r); 
}

int queryPath(int a, int b) {
	if(tin[a] < tin[b]) swap(a, b);

	if(head[a] == head[b]) return query(tin[b], tin[a], 1, 1, n);
	return query(tin[ head[a] ], tin[a], 1, 1, n) + queryPath(pai[ head[a] ], b);
}

void updatePath(int a, int b, int x) {
	if(tin[a] < tin[b]) swap(a, b);

	if(head[a] == head[b]){
		update(tin[b], tin[a], x, 1, 1, n);
		return;
	}
	
	update(tin[ head[a] ], tin[a], x, 1, 1, n); 
	updatePath(pai[ head[a] ], b, x);
}

int32_t main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfsInit(1, -1);
	decompose(1, 1);

	while(q--){
		int a, b, c, d; cin >> a >> b >> c >> d;
		updatePath(a, b, 1);

		cout << queryPath(c, d) << '\n';

		updatePath(a, b, -1);
	}
}
