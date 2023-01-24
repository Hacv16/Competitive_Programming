//Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

//Fast input
inline ll get(void) {
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    ll ret = 0;
    while (c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0'), c = getchar();
    return ret;
}

//Cin e Cout rapidos
ios_base::sync_with_stdio(false);
cin.tie(NULL);