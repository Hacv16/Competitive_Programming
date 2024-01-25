#define int long long
const int MOD = 1e9 + 7;

inline int mult(int a, int b) {return (a * b) % MOD;}

struct Matriz
{
    vector<vector<int>> mat;
    int n, m;

    static Matriz Id(int N)
    {
        Matriz id = Matriz(N, N);
        for (int i = 0; i < N; i++) id.mat[i][i] = 1;
        return id;
    }

    Matriz(int N = 0, int M = 0) : n(N), m(M)
    {
        mat.resize(N);
        for (auto &x : mat) x.resize(M);
    }

    Matriz(int N, int M, vector<vector<int>> Ma) : n(N), m(M), mat(Ma) {}

    Matriz operator* (Matriz outro)
    {
        assert(m == outro.n);
        Matriz resp = Matriz(n, outro.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < outro.n; j++)
            {
                resp.mat[i][j] = 0;
                for (int k = 0; k < m; k++)
                    resp.mat[i][j] += mult(mat[i][k], outro.mat[k][j]), resp.mat[i][j] %= MOD;
            }
        return resp;
    }
};
