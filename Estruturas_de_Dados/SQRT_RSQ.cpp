struct SQRT{
    ll v[MAX] = {0}, sum[MAX] = {0}, block[MAX], l[MAX], r[MAX];

    void init(int n){
        int T = sqrt(n) + 1;

        for(int i = 1; i <= n; i++)
            block[i] = i / T, r[block[i]] = i;
 
        for(int i = n; i > 0; i--)
            l[block[i]] = i;
    }

    void update(int i, ll x){
        sum[block[i]] += x;
        v[i] += x;
    }

    ll query(int a, int b){
        ll ans = 0;
 
        for(int i = a; i <= b && block[i] == block[a]; i++)
            ans += v[i];
 
        for(int i = block[a] + 1; i < block[b]; i++)
            ans += sum[i];
 
        if(block[a] != block[b]){
            for(int i = b; block[i] == block[b]; i--)
                ans += v[i];
        }

        return ans;
    }
};
