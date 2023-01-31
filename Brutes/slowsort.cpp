#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void slowsort(int l, int r){
	if(l >= r) return;

	int m = (l + r) / 2;
	slowsort(l, m);
	slowsort(m + 1, r);

	if(v[r] < v[m]) swap(v[r], v[m]);

	slowsort(l, r - 1);
}

int main(void){
	int n; cin >> n;

	v.resize(n);
	for(int &x : v) cin >> x;

	slowsort(0, n - 1);

	for(auto x : v)
		cout << x << ' ';
}
