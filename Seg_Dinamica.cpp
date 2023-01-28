vector<ll> seg, getL, getR, getId;

ll create(void){
    seg.push_back(-1);
    getL.push_back(0);
    getR.push_back(0);;
    getId.push_back(-1);
    return seg.size() - 1;
}

void update(ll i, ll x, ll idx, ll p, ll l, ll r){
    if(i > r || i < l) return;
    if(l == r){
        seg[p] = x;
        getId[p] = idx;
        return;
    }

    ll m = (l + r) >> 1;

    if(i <= m){
        if(getL[p] == 0) { ll aux = create(); getL[p] = aux; }
        update(i, x, idx, getL[p], l, m);

    }else{
        if(getR[p] == 0) { ll aux = create(); getR[p] = aux; }
        update(i, x, idx, getR[p], m + 1, r);
    }

    seg[p] = max(seg[getL[p]], seg[getR[p]]);
}

ll bb(ll x, ll p, ll l, ll r){
    if(seg[p] < x || l > x) return -1;
    if(l == r) return getId[p];
    ll m = (l + r) >> 1;
    if(seg[getL[p]] >= x) return bb(x, getL[p], l, m);
    return bb(x, getR[p], m + 1, r);
}
