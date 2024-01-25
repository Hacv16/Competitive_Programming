/*
    A ideia eh fazer uma seg persistente usando ponteiros
    Modelo eh o problema DQUERY (https://www.spoj.com/problems/DQUERY/)
    Criado por Fernando, 23/01/2023 22:57
*/
#include <bits/stdc++.h>
using namespace std;
struct SegPersistente
{
    int quant;
    int ini, fim;
    SegPersistente* e;
    SegPersistente* d;

    SegPersistente(int Q = 0, int INI = 0, int FIM = 0) {quant = Q; ini = INI; fim = FIM; e = this; d = this;}

    SegPersistente* update(int id, int val)
    {
        SegPersistente* novo = new SegPersistente;
        *novo = *this;
        if (ini == fim)
        {
            quant = val;
            // if (quant == 0) marc = 0;
            // else if (quant == 1) marc = 1;
            return novo;
        }
        int m = (ini + fim) >> 1;
        if (id <= m)
        {
            //Cuidado no c++11, da problema
            novo->e = e->update(id, val);
        }
        else
        {
            //Cuidado no c++11, da problema
            novo->d = d->update(id, val);
        }
        novo->quant = (novo->e)->quant + (novo->d)->quant;
        // novo->marc  = (novo->e)->marc  + (novo->d)->marc ;
        return novo;
    }

    int query(int p, int q)
    {
        if (q < ini || p > fim) return 0;
        if (p <= ini && fim <= q) return quant;
        int m = (ini + fim) >> 1;
        return (e->query(p, q) + d->query(p, q));
    }
};
SegPersistente nulo(0, 0, 0);
const int MAXN = 1e6 + 10;
vector<SegPersistente*> raiz;
int lastX[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    raiz[0] = new SegPersistente;
    raiz[0]->e = raiz[0]->d = &nulo;
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        raiz[i] = raiz[i-1]->update(lastX[x], 0);
        raiz[i] = raiz[i]->update(i, +1);
        lastX[x] = i;
    }
    int Q;
    cin >> Q;
    for (int q = 1; q <= Q; q++)
    {
        int X, Y;
        cin >> X >> Y;
        cout << raiz[Y]->query(X, Y) << '\n';
    }
}
