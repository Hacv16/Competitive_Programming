const int MAX = 2e6 + 15;

int pre[MAX], low[MAX], seen[MAX], artP[MAX], t;
vector<pair<int, int>> bridges;

void dfs(int u, int p){
	pre[u] = low[u] = ++t;
	seen[u] = true;

	int children = 0;

	for(auto v : adj[u]){
		if(v == p) continue;

		if(seen[v]){ //back edge
			low[u] = min(low[u], pre[v]);

		}else{
			dfs(v, u); children++;
			low[u] = min(low[u], low[v]);

			if(low[v] > pre[u]){ //achamos ponte
				bridges.emplace_back(u, v);
			}

			if(low[v] >= pre[u] && p != -1){ // p == -1 -> p eh a raiz (convencao)
                artP[u] = true;
            }
		}
	}

	if(p == -1 && children > 1){ //corner: raiz
		artP[u] = true;
	}
}