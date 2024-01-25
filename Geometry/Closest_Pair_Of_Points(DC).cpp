void solve(ll l, ll r){
    if(l == r) return;
    if(l == r - 1){
        if(v[l].dist(v[r]) < ans) ans = v[l].dist(v[r]), a = v[l].id, b = v[r].id;
        return;
    } 
 
    ll mid = (l + r) >> 1;  
    solve(l, mid);
    solve(mid + 1, r);
 
    ll aux = 0;
    vector<pt> cur;
 
    for(int i = l; i <= r; i++)
        if(abs(v[i].x - v[mid].x) < ans) cur.pb(v[i]);
    
    sort(all(cur), cmp2);
 
    for(int i = 0; i < sz(cur); i++)
        for(int j = i + 1; j < sz(cur) && abs(cur[i].y - cur[j].y) < ans; j++)
            if(cur[i].dist(cur[j]) < ans) ans = cur[i].dist(cur[j]), a = cur[i].id, b = cur[j].id;
}
