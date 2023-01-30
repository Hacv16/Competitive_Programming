#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, bool> psb;
 
const int MAX = 2e6 + 15;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
 
#define pb push_back
#define sz(x) (int) x.size()
#define fr first
#define sc second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << ": " << "[ " << x << " ]\n"
 
int n, m, seen[MAX], c[MAX], f[MAX];
vector<int> adj[MAX], rev[MAX], order;
 
void dfs(int u){
 	seen[u] = true;
 
 	for(auto v : adj[u])
      	if(!seen[v]) dfs(v);
 
 	order.pb(u);
}
 
void kdfs(int u, int cur){ //kosaraju dfs
 	seen[u] = true;
 	c[u] = cur;
 
 	for(auto v : rev[u])
      	if(!seen[v]) kdfs(v, cur);
}
 
void makeEdge(int a, bool na, int b, int nb){
    a = 2 * a ^ na, b = 2 * b ^ nb;
    int not_a = a ^ 1, not_b = b ^ 1;
 
    adj[not_a].pb(b); 
    adj[not_b].pb(a);
    rev[b].pb(not_a);
    rev[a].pb(not_b);
}
 
pii read(void){
    int x; char c; cin >> c >> x; x--;
    return {x, (c == '-')};
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> m >> n;
 
    bool ans = true;
	 
 	for(int i = 0; i < m; i++){
      	pii a = read(), b = read();
        makeEdge(a.fr, a.sc, b.fr, b.sc);
 	}
 
    for(int i = 0; i < 2 * n; i++)
        if(!seen[i]) dfs(i);
 
    reverse(all(order));
    memset(seen, false, sizeof(seen));
    
    int scc = 0;
 
    for(auto v : order)
        if(!seen[v]) kdfs(v, scc++);
    
    for(int i = 0; i < 2 * n; i += 2)
        ans &= (c[i] != c[i + 1]);
 
    if(!ans){
        cout << "IMPOSSIBLE" << '\n';
    }else{
        for(int i = 0; i < 2 * n; i += 2)
            cout << (c[i] > c[i + 1] ? '+' : '-') << ' ';
    }
 
	return 0;
}
