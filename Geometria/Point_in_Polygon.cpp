bool inPolygon(pt p){
    int l = 1, r = sz(hull) - 1;

    while(l <= r){
        int mid = (l + r) >> 1;
        if(!cw(hull[0], hull[mid], p)) r = mid - 1;
        else l = mid + 1;
    }

    if(l == 1 || !ccw(hull[0], hull.back(), p) || !cw(hull[l - 1], hull[l], p)) return false;
    return true;
}
