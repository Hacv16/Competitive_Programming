    while(r - l > 3){
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
 
        if(f(m1) < f(m2)) r = m2;
        else l = m1;
    }
 
    for(ll i = l; i <= r; i++)
        ans = min(ans, f(i));
