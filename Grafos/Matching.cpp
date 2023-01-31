bool dfs(int u){
    for(auto v : adj[u]){
        if(marcB[v]) continue;
 
        marcB[v] = true;
 
        if(matchB[v] == -1 || dfs(matchB[v])){
            matchA[u] = v;
            matchB[v] = u;
            return true;
        }
    }
 
    return false;
}
 
void getMatching(void){
    int ans = 0, aux = 1;
 
    while(aux){
        aux = false;
 
        for(int j = n + 1; j <= n + m; j++)
            marcB[j] = false;
 
        for(int i = 1; i <= n; i++){
            if(matchA[i] == -1 && dfs(i))
                aux = true, ans++;
        }
    }
 
    cout << ans << '\n';
 
    for(int i = 1; i <= n; i++)
        if(matchA[i] != -1) cout << i << ' ' << matchA[i] - n << '\n';
}
