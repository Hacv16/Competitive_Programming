vector<int> seg[4 * MAX];
 
void build(int p, int l, int r){
  if(l == r){
    seg[p].pb(v[l]);
    return;
  }
 
  int m = (l + r) >> 1, e = 2 * p, d = e + 1;
  build(e, l, m); build(d, m + 1, r);
 
  seg[p].resize(r - l + 1);
 
  merge(seg[e].begin(), seg[e].end(), seg[d].begin(), seg[d].end(), seg[p].begin());
}
 
int query(int a, int b, int p, int l, int r, int val){
  if(a > r || b < l) return 0;
  if(a <= l && r <= b) return seg[p].end() - lower_bound(seg[p].begin(), seg[p].end(), val);
 
  int m = (l + r) >> 1, e = 2 * p, d = e + 1;
  return query(a, b, e, l, m, val) + query(a, b, d, m + 1, r, val);
}
