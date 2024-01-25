const int MAX = 510;
const int INF = 0x3f3f3f3f;

int dp[MAX][MAX];

int main(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = (i == j ? 0 : INF);

	while(m--){
		int u, v, w; cin >> u >> v >> w;
		dp[u][v] = min(dp[u][v], w);
		dp[v][u] = min(dp[v][u], w);
	}

	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}
