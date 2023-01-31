/*
  Problema modelo eh o ORDERSET (https://www.spoj.com/problems/ORDERSET/)
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
//No multiset, o lower_bound e upper_bound tem função invertida: lower_bound pega o primeiro
//Maior e upper_bound pega o primeiro maior ou igual
ordered_set s;
ordered_multiset ms;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> Q;
    while (Q--)
    {
        char type;
        cin >> type;
        if (type == 'I')
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (type == 'D')
        {
            int x;
            cin >> x;
            s.erase(x);
        }
        else if (type == 'K')
        {
            int x;
            cin >> x;
            --x;
            auto it = s.find_by_order(x);
            if (it == s.end()) cout << "invalid" << '\n';
            else cout << *it << '\n';
        }
        else
        {
            int x;
            cin >> x;
            cout << s.order_of_key(x) << '\n';
        }
    }
}
