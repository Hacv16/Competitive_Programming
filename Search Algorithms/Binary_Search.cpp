int l = 0, r = INF, resp = -1;

while(l <= r){
  int m = (l + r) >> 1;
  if(f(m)) resp = m, l = m + 1;
  else r = m - 1;
}
