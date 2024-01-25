/*
    Union-Find Structure that supports rollback operations
    Note that path compression cannot be used.

    Complexity: O(logN) per find/union operation
                O(1) per rollback operation
*/


#include <bits/stdc++.h>
using namespace std;
vector<int> pai, sub;
stack<tuple<int, int, int> > oper;
//       filho   pai   tempo
int tmp = 0;

int find(int v) {return ((pai[v] == v) ? v : find(pai[v]));}

void une(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) {oper.emplace(-1, -1, ++tmp); return;}
    if (sub[a] < sub[b]) swap(a, b);
    pai[b] = a;
    sub[a] += sub[b];
    oper.emplace(b, a, ++tmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    pai.resize(N+1); sub.resize(N+1);
    iota(pai.begin(), pai.end(), 0);
    fill(sub.begin(), sub.end(), 1);
    int Q;
    cin >> Q;
    while (Q--)
    {
        char type;
        cin >> type;
        if (type == '+')
        {
            int x, y;
            cin >> x >> y;
            une(x, y);
        }
        else if (type == '?')
        {
            int x;
            cin >> x;
            cout << sub[find(x)] << '\n';
        }
        else
        {
            int t;
            cin >> t;
            if (oper.empty()) continue;
            auto [a, b, t1] = oper.top();
            while (!oper.empty() && t <= t1)
            {
                oper.pop();
                if (a != -1) {pai[a] = a; sub[b] -= sub[a];}
                if (!oper.empty())
                {
                    tuple<int, int, int> aux = oper.top();
                    a = get<0>(aux); b = get<1>(aux); t1 = get<2>(aux);
                }
            }
        }
    }
}
