//Problemas Base: DQUERY, MKTHNUM

vector<ll> seg, getL, getR, raizes;

ll create(void){
    seg.push_back(-1);
    getL.push_back(0);
    getR.push_back(0);;
    return seg.size() - 1;
}

ll query(ll a, ll b, ll p, ll l, ll r){
    if(a > r || b < l) return 0;
    if(a <= l && r <= b) return seg[p];
    ll m = (l + r) >> 1, e = getL[p], d = getR[p];
    return query(a, b, e, l, m) + query(a, b, d, m + 1, r);
}

ll update(ll i, ll x, ll p, ll l, ll r){
    ll novo = create();

    seg[novo] = seg[p];
    getL[novo] = getL[p];
    getR[novo] = getR[p];

    if(l == r){
        seg[novo] += x;
        return;
    }

    ll m = (l + r) >> 1;

    if(i <= m) getL[novo] = update(i, x, getL[novo], l, m);
    else getR[novo] = update(i, x, getR[novo], m + 1, r);

    seg[novo] = seg[getL[novo]] + seg[getR[novo]];

    return novo;
}
