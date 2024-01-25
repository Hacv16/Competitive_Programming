ll pick(vector<pt> &v){
    ll A = 0, B = 0, n = sz(v);

    for(int i = 0; i < n; i++){
        A += tri(pt(0, 0), v[i], v[(i + 1) % n]);
        pt aux = v[(i + 1) % n] - v[i];
        B += abs(__gcd(aux.x, aux.y));
    }

    A = abs(A) / 2;
    return A + 1 - B / 2;
}
