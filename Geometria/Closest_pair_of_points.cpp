 v.pb(pt());
 
    for(int i = 1; i <= n; i++){
        ll x; cin >> x; 
        s[i] = s[i - 1] + x;
        v.pb(pt(s[i], i));
    }
 
    sort(all(v));
    ll j = 1;
 
    for(int i = 1; i <= n; i++){
        aux.insert({v[i].y, i});
 
        while(aux.size() && (v[j].x - v[i].x) * (v[j].x - v[i].x) > d)
            aux.erase({v[j].y, j}), j++;
        
        auto it = aux.find({v[i].y, i});
 
        if(it != --aux.end()){
            auto st = it; ++st;
 
            for(auto itr = st; itr != aux.end(); itr++){
                ll cur = (itr -> fr - v[i].y) * (itr -> first - v[i].y);
                if (cur >= d) break;
                d = min(d, v[i].dist(v[itr -> sc]));
            }
        }
 
        if(it != aux.begin()){
            auto st = it; --st;
 
            for(auto itr = st; ; itr--){
                ll cur = (itr -> fr - v[i].y) * (itr -> first - v[i].y);
                if (cur >= d) break;
                d = min(d, v[i].dist(v[itr -> sc]));
 
                if(itr == aux.begin()) break;
            }
        }
    }
