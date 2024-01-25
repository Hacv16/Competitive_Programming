/* 
	Slow(est) sorting algorithm. No practical use. Still, quite funny.
	Complexity: ?
*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
	srand(time(0));

	int n; cin >> n;
	vector<int> v(n);

	for(auto &x : v) cin >> x;

	while(!is_sorted(v.begin(), v.end()))
		random_shuffle(v.begin(), v.end());

	for(auto x : v)
		cout << x << ' ';
}
