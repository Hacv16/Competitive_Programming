#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int MAX = 2e6 + 15;
const int INF = 0x3f3f3f3f;
 
ll n, k, sub[MAX], f[MAX], ans;
bool removed[MAX];
vector<ll> adj[MAX], update;
 
void dfsini(int u, int p){
     sub[u] = 1;
 
     for(auto v : adj[u]){
          if(v == p || removed[v]) continue;
 
          dfsini(v, u);
          sub[u] += sub[v];
     }
}
 
int findCentroid(int u, int p, int sz){
     for(auto v : adj[u]){
          if(removed[v] || v == p) continue;
 
          if(sub[v] > sz / 2)
               return findCentroid(v, u, sz);
     }
 
     return u;
}
 
void dfscalc(int u, int p, int d){
     update.push_back(d);
     if(k >= d) ans += f[k - d];
 
     for(auto v : adj[u]){
          if(v == p || removed[v]) continue;
          dfscalc(v, u, d + 1);
     }
}
 
void decompose(int u){
     dfsini(u, -1);
     int centroid = findCentroid(u, u, sub[u]);
 
     removed[centroid] = true;
 
     f[0]++;
 
     for(auto v : adj[centroid]){
          if(removed[v]) continue;
          dfscalc(v, centroid, 1);
 
          for(auto x : update) f[x]++;
          update.clear();
     }
 
     for(int i = 0; i <= sub[u]; i++)
          f[i] = 0;
 
     //divide
 
     for(auto v : adj[centroid])
          if(!removed[v]) decompose(v);
}
 
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
 
     cin >> n >> k;
 
     for(int i = 1; i < n; i++){
          int u, v; cin >> u >> v;
          adj[v].push_back(u);
          adj[u].push_back(v);
     }
 
     decompose(1);
 
     cout << ans << '\n';
 
     return 0;
}
