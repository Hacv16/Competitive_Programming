class SparseSeg{
	public:
		int create(void){
			seg.emplace_back(0);
			getL.emplace_back(0);
			getR.emplace_back(0);
			return seg.size() - 1;
		}

		void setUp(){ 
			seg.clear(); getL.clear(); getR.clear();
			create(); create(); 
		}

		int getLeft(int p){
			if(getL[p] == 0){ int aux = create(); getL[p] = aux; }
			return getL[p];
		}

		int getRight(int p){
			if(getR[p] == 0){ int aux = create(); getR[p] = aux; }
			return getR[p];
		}

		void update(int i, int x, int p, int l, int r){
			if(i < l || i > r) return;
			if(l == r){
				seg[p] = x;
				return;
			}

			int m = (l + r) >> 1;

			update(i, x, getLeft(p), l, m);
			update(i, x, getRight(p), m + 1, r);

			seg[p] = seg[ getL[p] ] + seg[ getR[p] ];
		}

		int query(int a, int b, int p, int l, int r){
			if(a > r || b < l || p == 0) return 0;
			if(a <= l && r <= b) return seg[p];

			int m = (l + r) >> 1;	
			return query(a, b, getL[p], l, m) + query(a, b, getR[p], m + 1, r);
		}

		int bbin(int x, int p, int l, int r){
			if(seg[p] < x) return -1;

			if(l == r) return l;
			int m = (l + r) >> 1;

			if(seg[ getL[p] ] >= x) return bbin(x, getL[p], l, m);
			return bbin(x - seg[ getL[p] ], getR[p], m + 1, r);
		}

	protected:
		vector<ll> seg, getL, getR;
};
