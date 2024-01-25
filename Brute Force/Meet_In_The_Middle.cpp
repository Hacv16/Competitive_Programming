/*
    Basic idea is to divide a set into two halves, calculate some informations
    for each half and then combine these informations.

    Complexity: O(2^(N/2))
*/

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
 
ll n, s, ans;
vector<ll> a, b;
 
vector<ll> subs(vector<ll>&v
){
    ll n = sz(v);
    vector<ll> ans;
 
    for(ll mask = 0; mask < (1LL << n); mask++){
        ll cur = 0;
 
        for(ll i = 0; i < n; i++)
            if(mask & (1LL << i)) cur += v[i];
 
        ans.pb(cur);
    }
 
    sort(all(ans));
 
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    cin >> n >> s;
 
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
 
        if(i < n / 2) a.pb(x);
        else b.pb(x);
    }
 
    vector<ll> sa = subs(a), sb = subs(b);
 
    for(auto x : sa)
    {
        ll idx1 = lower_bound(all(sb), s - x) - sb.begin();
        ll idx2 = upper_bound(all(sb), s - x) - sb.begin();
 
        if(x + sb[idx1] == s) ans += (idx2 - idx1);
    }
 
    cout << ans << '\n';
}
