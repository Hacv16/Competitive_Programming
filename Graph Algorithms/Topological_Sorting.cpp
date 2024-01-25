
queue<int> q; 
vector<int> process;

for(int i = 1; i <= n; i++)
    if(ingrau[i] == 0) q.push(i);

while(!q.empty())
{
    int u = q.front(); q.pop();
    process.push_back(u);

    for(auto v : adj[u])
        if(--ingrau[v] == 0)
            q.push(v);
}
