bool inutil(ll i, ll j, ll k){
    return (ld) (b[k] - b[i]) / (m[i] - m[k]) <= (ld) (b[j] - b[i]) / (m[i] - m[j]);
}
 
void add(ll a, ll k){ //add y = ax + k
    m.push_back(a);
    b.push_back(k);
 
    while(sz(m) >= 3 && inutil(m.size() - 3, m.size() - 2, m.size() - 1)){
        m.erase(m.end() - 2);
        b.erase(b.end() - 2);
    }
}
 
ll f(ll i, ll x){
    return m[i] * x + b[i];
}
 
ll query(ll x){
    if (ptr >= sz(m)) ptr = sz(m) - 1;
    while (ptr < sz(m) - 1 && f(ptr + 1, x) <= f(ptr, x)) ++ptr;
 
    return f(ptr, x);
}
 
