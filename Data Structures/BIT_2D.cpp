/*
    Basic structure of a 2D Binary Indexed Tree.
    Complexity: O(log^2(N)) per operation
*/

void update(int x, int y, int v){
    for(int i = x; i <= n; i += (i & -i))
        for(int j = y; j <= n; j += (j & -j))
            BIT[i][j] += v;
}
 
int sum(int x, int y){ // A function to get sum from (0, 0) to (x, y)
    int s = 0;
 
    for(int i = x; i > 0; i -= (i & -i))
        for(int j = y; j > 0; j -= (j & -j))
            s += BIT[i][j];
 
    return s;
}
 
int query(int x1, int y1, int x2, int y2){  //rectangle query
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}
 
