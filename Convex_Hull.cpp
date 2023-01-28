struct pt{
    ll x, y;
    pt(ll a = 0, ll b = 0){x = a, y = b;}

    //Perpendicular a dot b = 0, Paralelo a cross b = 0
    pt operator + (pt p){ return pt(x + p.x, y + p.y);   } //soma
    pt operator - (pt p){ return pt(x - p.x, y - p.y);   } //subtracao
    ll operator % (pt p){ return x * p.y - y * p.x;      } //cross (sen)
    ll operator * (pt p){ return x * p.x + y * p.y;      } //dot   (cos)
    bool operator == (pt p){ return x == p.x && y == p.y;} //equal
    
    bool operator < (pt p){
        if(x == p.x) return y < p.y; 
        return x < p.x;
    }

    pt mid(pt p){return pt((x + p.x) / 2, (y + p.y) / 2);}                   //ponto medio
    ll dist(pt p){ll dx = x - p.x, dy = y - p.y; return dx * dx + dy * dy;}  //tio pit
}; 

ll tri(pt a, pt b, pt c){ return (b - a) % (c - a); }
bool cw(pt a, pt b, pt c){return tri(a, b, c) < 0;  }
bool ccw(pt a, pt b, pt c){return tri(a, b, c) > 0; }

vector<pt> hull(vector<pt> v){
    sort(all(v));

    vector<pt> lowH, uppH, hull;

    for(int i = 0; i < sz(v); i++){
        while(sz(uppH) > 1 && !cw(uppH[sz(uppH) - 2], uppH.back(), v[i]))
            uppH.pop_back();

        while(sz(lowH) > 1 && !ccw(lowH[sz(lowH) - 2], lowH.back(), v[i]))
            lowH.pop_back();

        lowH.pb(v[i]), uppH.pb(v[i]);
    }
    
    hull = uppH;
    lowH.pop_back();

    for(int i = sz(lowH) - 1; i > 0; i--)
        hull.pb(lowH[i]);

    reverse(all(hull));

    return hull;
}
