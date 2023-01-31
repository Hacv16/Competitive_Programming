void dfs(int u, int p){
    dp[u].insert(c[u]);
 
    for(auto v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
        
        if(sz(dp[u]) < sz(dp[v]))
            swap(dp[u], dp[v]);
        
        for(auto x : dp[v])
            dp[u].insert(x);
    }
 
    ans[u] = sz(dp[u]);
}
