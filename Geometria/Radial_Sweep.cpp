struct pt{
    ll x, y, id;
    pt(ll a = 0, ll b = 0, ll c = 0){x = a, y = b, id = c;}

    ll quad(void) const{
        if(0 <= x && 0 <= y) return 1;
        if(0 > x && 0 <= y) return 2;
        if(0 > x && 0 > y) return 3;
        return 4;
    }

    //Perpendicular a dot b = 0, Paralelo a cross b = 0
    pt operator + (pt p) const{ return pt(x + p.x, y + p.y, id);   } //soma
    pt operator - (pt p) const{ return pt(x - p.x, y - p.y, id);   } //subtracao
    ll operator % (pt p) const{ return x * p.y - y * p.x;          } //cross (sen)
    ll operator * (pt p) const{ return x * p.x + y * p.y;          } //dot   (cos)
    bool operator == (pt p) const{ return x == p.x && y == p.y;    } //equal

    bool operator < (pt p) const{   //radial sorting
        if((*this).quad() != p.quad()) return (*this).quad() < p.quad();
        if((*this) % p == 0) return (*this) * (*this) < p * p; //dist
        return (*this) % p > 0;
    }

    pt mid(pt p){return pt((x + p.x) / 2, (y + p.y) / 2);}                                          //ponto medio
    ll dist(pt p){ll dx = x - p.x, dy = y - p.y; return dx * dx + dy * dy;}                         //tio pit
    ld getAngle(pt p){ld t = atan2((*this) % p, (*this) * p); if(t < 0) t = abs(t) + PI; return t;}
}; 
