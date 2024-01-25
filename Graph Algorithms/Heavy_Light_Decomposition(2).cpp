#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int maxn = 200010;
const int inf = 1000000010;
 
int n, q;
int curTime;
 
int tin[maxn], v[maxn];
int head[maxn], anc[maxn];
int sub[maxn], depth[maxn];
 
vector<int> adj[maxn];
 
ll sum[4*maxn];
 
void updateSEG(int node, int l, int r, int i, int value)
{
    if( i < l || r < i )
        return;
 
    if( l == r )
    {
        sum[node] = value;
        return;
    }
 
    int m = ( l + r )/2;
 
    updateSEG( 2*node , l , m , i , value );
    updateSEG( 2*node + 1 , m + 1 , r , i , value );
 
    sum[node] = sum[2*node] + sum[2*node + 1];
}
 
ll querySEG(int node, int l, int r, int i, int j)
{
    if( j < l || r < i )
        return 0;
 
    if( i <= l && r <= j )
        return sum[node];
 
    int m = ( l + r )/2;
 
    ll sumLeft = querySEG( 2*node , l , m , i , j );
    ll sumRight = querySEG( 2*node + 1 , m + 1 , r , i , j );
 
    return sumLeft + sumRight;
}
 
void DFSInit(int node, int ancestor)
{
    sub[node] = 1; anc[node] = ancestor;
 
    for(int i = 0 ; i < (int)adj[node].size() ; i++)
    {
        int neighbor = adj[node][i];
 
        if( neighbor == ancestor )
            continue;
 
        depth[neighbor] = depth[node] + 1;
 
        DFSInit( neighbor , node );
 
        sub[node] += sub[neighbor];
 
        if( adj[node][0] == ancestor || sub[neighbor] > sub[ adj[node][0] ] )
            swap( adj[node][0] , adj[node][i] );
    }
}
 
void decompose(int node, int curHead)
{
    head[node] = curHead;
    tin[node] = ++curTime;
 
    if( !adj[node].empty() && adj[node][0] != anc[node] )
        decompose( adj[node][0] , curHead );
 
    for(int i = 1 ; i < (int)adj[node].size() ; i++)
    {
        int neighbor = adj[node][i];
 
        if( neighbor != anc[node] )
            decompose( neighbor , neighbor );
    }
}
 
ll queryHLD(int node)
{
    ll ans = 0;
 
    while( node != 0 )
    {
        ans += querySEG( 1 , 1 , n , tin[ head[node] ] , tin[node] );
        node = anc[ head[node] ];
    }
    
    return ans;
}
 
void updateHLD(int node, int value) { updateSEG( 1 , 1 , n , tin[node] , value ); }
 
int main()
{
    cin >> n >> q;
 
    for(int i = 1 ; i <= n ; i++)
        cin >> v[i];
 
    for(int i = 1 ; i < n ; i++)
    {
        int a, b;
        cin >> a >> b;
 
        adj[a].push_back( b );
        adj[b].push_back( a );
    }
 
    DFSInit( 1 , 0 );
    decompose( 1 , 1 );
 
    for(int i = 1 ; i <= n ; i++)
        updateHLD( i , v[i] );
 
    for(int i = 1 ; i <= q ; i++)
    {
        int type;
        cin >> type;
 
        if( type == 1 )
        {
            int s, x;
            cin >> s >> x;
 
            updateHLD( s , x );
        }
        
        if( type == 2 )
        {
            int s;
            cin >> s;
 
            cout << queryHLD( s ) << endl;
        }
    }
}
