inline int f(int i, int x){ return m[i] * x + b[i]; }
 
inline bool inutil(int i, int j, int k)
{
	int l = (b[k] - b[i]) * (m[i] - m[j]);
	int r = (b[j] - b[i]) * (m[i] - m[k]);
	return l <= r;
}
 
inline void add(int a, int k) //add ax + k
{
	m.push_back(a); b.push_back(k);
 
	while(m.size() >= 3 && inutil(sz(m) - 3, sz(m) - 2, sz(m) - 1))
	{
		m.erase(m.end() - 2);
		b.erase(b.end() - 2);
	}
}
 
int query(int x)
{
	if(p >= m.size()) p = m.size() - 1;
	while(p < m.size() - 1 && f(p + 1, x) < f(p, x)) p++;
	return f(p, x);
}	
