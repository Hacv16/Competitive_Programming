const int MAX = 100; //tamanho

struct Matrix{
    vector<vector<ll>> m = vector<vector<ll>>(MAX, vector<ll>(MAX));

    Matrix operator * (Matrix other){
        Matrix prod;

        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < MAX; j++)
                for(int k = 0; k < MAX; k++)
                    prod.m[i][k] += m[i][j] * other.m[j][k], prod.m[i][k] %= MOD;

        return prod;
    }
};

Matrix fpow(Matrix b, ll e){ 
    if(e == 0) return ID; //Matriz identidade
    if(e % 2 == 0) return fpow(b * b, e >> 1);
    return b * fpow(b, e - 1);
}
