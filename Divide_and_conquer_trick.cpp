void dct(int l, int r, int optL, int optR, int k){
	if(l > r) return;

	int m = (l + r) >> 1, optV = INF, opt = -1;

	for(int i = optL; i <= min(optR, m); i++){
		int cur = dp[i - 1][k - 1] + cost(i, m);
		if(cur < optV) optV = cur, opt = i;
	}

	dp[m][k] = optV;

	dct(l, m, optL, opt, k);
	dct(m + 1, r, opt, optR);
}
