#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e6 + 15;
const int INF = 0x3f3f3f3f;

ll n, m, d[MAX];
vector<tuple<ll, ll, ll>> edges;

int32_t main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    cin >> n >> m;

    while(m--){
        ll u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    ll source = 1; cin >> source;

    for(int i = 1; i <= n; i++)
        d[i] = (i == source ? 0 : INF);

    while(true){
        bool notDone = false;

        for(auto edge : edges){
            ll u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);

            if(d[u] < INF){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    notDone = true;
                }
            } 
        }

        if(!notDone) break;
    }

    for(int i = 1; i <= n; i++)
        cout << (d[i] == INF ? -1 : d[i]) << ' ';
} 
