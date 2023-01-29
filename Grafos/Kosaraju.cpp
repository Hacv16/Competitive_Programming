const int MAX = 2e6 + 15;

int seen[MAX][2], comp[MAX];
vector<int> adj[MAX], rev[MAX], order;

int dfs(int u){
	seen[u][0] = true;

	for(auto v : adj[u])
		if(!seen[v][0]) dfs(v);
	
	order.push_back(u);
}

void kdfs(int u, int c){
	seen[u][1] = true;
	comp[u] = c;

	for(auto v : rev[u])
		if(!seen[v][1]) kdfs(v, c);
}

void kosaraju(){
	for(int i = 1; i <= n; i++)
		if(!seen[i][0]) dfs(i);

	reverse(order.begin(), order.end()); //Importante

	int scc = 0;

	for(auto node : order) //nao esquecer de utilizar o vetor order (dica : so usar auto)
		if(!seen[node][1]) kdfs(node, ++scc);
}
