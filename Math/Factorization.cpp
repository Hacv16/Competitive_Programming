void factorization(int k, vector<int>& primes)
{
	for(int g = 2; g * g <= k; g++)
	{
		while(k % g == 0)
		{
			k /= g;
			primes.push_back(g);
		}
	}

	if(k != 1) primes.push_back(k);
}