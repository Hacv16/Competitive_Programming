class sparseSeg{
	public:
		int create(void){
			seg.push_back(0);
			getL.push_back(-1);
			getR.push_back(-1);
			return seg.size() - 1;
		}

		void initiate(){ create(); create(); }

		void update(ll i, ll x, ll p, ll l, ll r){
			if(i < l || i > r) return;
			if(l == r){
				seg[p] += x;
				return;
			}

			ll m = (l + r) >> 1;

			if(getL[p] == -1){ int aux = create(); getL[p] = aux; }
			update(i, x, getL[p], l, m);

			if(getR[p] == -1){ int aux = create(); getR[p] = aux; } 
			update(i, x, getR[p], m + 1, r);

			seg[p] = seg[ getL[p] ] + seg[ getR[p] ];
		}

		ll query(ll a, ll b, ll p, ll l, ll r){
			if(a > r || b < l) return 0;
			if(a <= l && r <= b) return seg[p];

			ll m = (l + r) >> 1, ans = 0;

			if(getL[p] != -1) ans += query(a, b, getL[p], l, m);
			if(getR[p] != -1) ans += query(a, b, getR[p], m + 1, r);

			return ans;
		}

	protected:
		vector<ll> seg, getL, getR;
};
