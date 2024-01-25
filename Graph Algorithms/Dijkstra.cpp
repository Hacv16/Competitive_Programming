int dijkstra(int o, int f)
{
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	dist[o] = 0; q.emplace(0, o);

	while(q.size())
	{
		auto [d, u] = q.top(); q.pop();
		if(dist[u] < d) continue;

		for(auto [v, w] : adj[u])
		{
			if(d + w < dist[v])
			{
				dist[v] = d + w;
				q.emplace(dist[v], v);
			}
		}
	}

	return dist[f];
}
