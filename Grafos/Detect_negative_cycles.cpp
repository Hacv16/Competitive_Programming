#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e6 + 15;
const int INF = 0x3f3f3f3f;

ll n, m;
vector<tuple<ll, ll, ll>> edges;

int32_t main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int tc; cin >> tc;

    while(tc--){
        cin >> n >> m;

        while(m--){
            ll u, v, w; cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
        }

        vector<ll> d(n + 1, 0);

        bool f = false;

        for(int i = 0; i < n; i++){
            f = false;

            for(auto edge : edges){
                ll u = get<0>(edge), v = get<1>(edge), w = get<2>(edge);

                if(d[v] > d[u] + w){
                    d[v] = d[u] + w; f = true;
                } 
            }
        }

        cout << (f ? "possible" : "not possible") << '\n';
        edges.clear();
    }
} 
