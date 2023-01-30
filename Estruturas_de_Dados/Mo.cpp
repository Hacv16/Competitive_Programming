#include<bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define fr first
#define sc second
 
typedef long long ll;
const int MAX = 2e6 + 15;
const int INF = 0x3f3f3f3f;
 
ll n, q, v[MAX], block[MAX], f[MAX], T, ans = 0, resp[MAX];
set<ll> aux;
map<ll, ll> comp;
 
struct Q{
    int l, r, idx;
 
    Q(int a = 0, int b = 0, int c = 0){
        l = a, r = b, idx = c;
    }
 
    bool operator < (Q other){
        int ba = block[l], bb = block[other.l];
        if(ba != bb) return ba < bb;
        return r < other.r;
    }
};
 
vector<Q> queries;
 
void add(int a){
    if(!f[a]) ans++;
    f[a]++;
}
 
void remove(int a){
    if(f[a] == 1) ans--;
    f[a]--;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
 
    T = sqrt(n) + 1;
 
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        aux.insert(v[i]);
    }
 
    ll cur = 1;
    for(auto x : aux)
        comp[x] = cur++;
 
    for(int i = 1; i <= n; i++)
        v[i] = comp[v[i]];
 
    for(int i = 1; i <= n; i++)
        block[i] = i / T;
 
    cin >> q;
 
    for(int i = 1; i <= q; i++){
        int l, r; cin >> l >> r;
        queries.push_back(Q(l, r, i));
    }
 
    sort(all(queries));
 
    int curl = 0, curr = -1;
 
    for(auto query : queries){
        int l = query.l, r = query.r;
 
        while(curl > l) add(v[--curl]);
        while(curr < r) add(v[++curr]);
        while(curl < l) remove(v[curl++]);
        while(curr > r) remove(v[curr--]);
 
        resp[query.idx] = ans;
    }
 
    for(int i = 1; i <= q; i++)
        cout << resp[i] << '\n';
 
    return 0;
}
