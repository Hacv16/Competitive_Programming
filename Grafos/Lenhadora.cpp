#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
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
 
int n, cycles, pai[MAX], mark[MAX];
int paiCiclo[MAX], numCiclo[MAX], tamCiclo[MAX], depth[MAX], ingrau[MAX];
 
void acheiCiclo(int u){
    cycles++;
 
    while(!mark[u]){
        mark[u] = true;
        numCiclo[u] = cycles;
        paiCiclo[u] = u;
        depth[u] = 0;
        tamCiclo[cycles]++;
 
        u = pai[u];
    }
}
 
void lenhadora(){
    queue<int> q;
    vector<int> prcs;
 
    for(int i = 1; i <= n; i++)
        if(ingrau[i] == 0) q.push(i);
 
    while(q.size()){
        int u = q.front(); q.pop();
        mark[u] = true; prcs.pb(u);
 
        ingrau[pai[u]]--;
 
        if(ingrau[pai[u]] == 0)
            q.push(pai[u]);
    }
 
    for(int i = 1; i <= n; i++)
        if(!mark[i]) acheiCiclo(i);
 
    for(int i = sz(prcs) - 1; i >= 0; i--){
        int u = prcs[i];
        depth[u] = depth[pai[u]] + 1;
        paiCiclo[u] = paiCiclo[pai[u]];
    }
}
 
int query(int u){
    return depth[u] + tamCiclo[numCiclo[paiCiclo[u]]];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    cin >> n;
 
    for(int i = 1; i <= n; i++){
        cin >> pai[i];
        ingrau[pai[i]]++;
    }
 
    lenhadora();
 
    for(int i = 1; i <= n; i++)
        cout << query(i) << ' ';
 
    cout << '\n';
 
    return 0;
}
