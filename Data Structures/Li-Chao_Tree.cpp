struct Line
{
	int a, b;
	Line(int x = 0, int y = INF) : a(x), b(y) { }

	int operator ()(int x){ return a * x + b; }
 
} seg[4 * MAXC];
 
void update(int p, int l, int r, Line f)
{
	int m = (l + r) >> 1, e = 2 * p, d = e + 1;
 
	bool lessMid = f(m) < seg[p](m);
	bool lessLeft = f(l) < seg[p](l);
 
	if(lessMid) swap(seg[p], f);
 
	if(l == r) return;
 
	if(lessMid != lessLeft) update(e, l , m , f);
	else update(d, m + 1 , r , f);
}
 
int query(int x, int p, int l, int r)
{
	if(l == r) return seg[p](x);
	int m = (l + r) >> 1, e = 2 * p, d = e + 1;
 
	if(x < m) return min(seg[p](x), query(x, e, l, m));
	else return min(seg[p](x), query(x, d, m + 1, r));
}
