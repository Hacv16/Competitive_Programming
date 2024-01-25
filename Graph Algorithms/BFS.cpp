queue<int> q;
vector<int> dist(n + 1, -1);

q.push(o);
dist[o] = 0;

while(!q.empty())
{
    int u = q.front(); q.pop();

    for(auto v : adj[u])
    {
        if(dist[v] == -1)
        {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}