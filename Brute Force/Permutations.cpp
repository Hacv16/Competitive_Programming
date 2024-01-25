/*
	Brute force all N! permutations of size N, in lexicographical order.
	Complexity: O(N! * N)
*/

vector<int> p(n);
iota(p.begin(), p.end(), 1);

do{
	for(auto x : p)
	{
		// Do something
	}

} while(next_permutation(p.begin(), p.end()))
