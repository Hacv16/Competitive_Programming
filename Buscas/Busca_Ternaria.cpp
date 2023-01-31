while(r - l >= 3){
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    if(f(m1) > f(m2)) r = m2;
    else l = m1;
}

ll ans = -INF;

for(int i = l; i <= r; i++)
    ans = max(ans, f(i));
