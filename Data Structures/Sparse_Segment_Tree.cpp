class SparseSeg
{
	public:
		int create(void)
		{
			int id = seg.size();

			seg.push_back(INF);
			getL.push_back(0);
			getR.push_back(0);

			return id;
		}

		void setUp()
		{ 
			seg.clear(); getL.clear(); getR.clear();
			create(); create(); 
		}

		int getLeft(int p)
		{
			if(getL[p] == 0){ int aux = create(); getL[p] = aux; }
			return getL[p];
		}

		int getRight(int p)
		{
			if(getR[p] == 0){ int aux = create(); getR[p] = aux; }
			return getR[p];
		}

		void update(int i, int x, int p, int l, int r)
		{
			if(i < l || i > r) return;
			
			if(l == r)
			{
				seg[p] = x;
				return;
			}

			int m = (l + r) >> 1;

			update(i, x, getLeft(p), l, m);
			update(i, x, getRight(p), m + 1, r);

			seg[p] = min(seg[ getLeft(p) ], seg[ getRight(p) ]);
		}

		int query(int a, int b, int p, int l, int r)
		{
			if(a > r || b < l || p == 0) return INF;
			if(a <= l && r <= b) return seg[p];

			int m = (l + r) >> 1;	
			return min(query(a, b, getL[p], l, m), query(a, b, getR[p], m + 1, r));
		}

	protected:
		vector<int> seg, getL, getR;
};
