vector<ll> bfs(int u){
    vector<ll> d(n + 1, LLINF);
    d[u] = 0;

    deque<ll> q;
    q.push_back(u);

    while(q.size()){
        ll u = q.front(); q.pop_front();
        
        for(auto e : adj[u]){
            ll v = e.fr, w = e.sc;

            if(d[v] > d[u] + w){
                d[v] = d[u] + w;

                if(w == 1) q.push_back(v);
                else q.push_front(v); 
            }
        }
    }

    return d;
}
