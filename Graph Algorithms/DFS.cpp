void dfs(int u)
{
    seen[u] = true;

    for(auto v : adj[u])
        if(!seen[v]) dfs(v);
}