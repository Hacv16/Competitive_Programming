#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int border = 1e6 + 10;
struct Line
{
    int l, b;
    Line(int L = 0, int B = 0) : l(L), b(B) {}

    int operator()(int x) {return l * x + b;}
};
class SparseSeg
{
protected:
    vector<Line> seg;
    vector<int> e, d;
public:
    int create()
    {
        seg.emplace_back(0, INF);
        e.push_back(0);
        d.push_back(0);
        return seg.size()-1;
    }

    void init()
    {
        seg.clear(); e.clear(); d.clear();
        create(); create();
    }

    int getLeft(int pos)
    {
        if (e[pos] == 0) {int aux = create(); e[pos] = aux;}
        return e[pos];
    }

    int getRight(int pos)
    {
        if (d[pos] == 0) {int aux = create(); d[pos] = aux;}
        return d[pos];
    }

    void update(int pos, int ini, int fim, Line val)
    {
        int m = (ini + fim) >> 1;
        if (val(m) < seg[pos](m)) swap(seg[pos], val);

        if (ini == fim) return;

        if (val(ini) < seg[pos](ini)) update(getLeft(pos), ini, m, val);
        else update(getRight(pos), m+1, fim, val);
    }

    int query(int pos, int ini, int fim, int id)
    {
        if (ini == fim || pos == 0) return seg[pos](ini);
        int m = (ini + fim) >> 1;
        if (id <= m) return min(seg[pos](id), query(e[pos], ini, m, id));
        else return min(seg[pos](id), query(d[pos], m+1, fim, id));
    }
};
