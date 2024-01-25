void findDivisors(int k, vector<int>& divisors)
{
	for(int g = 1; g * g <= k; g++)
	{
		if(k % g == 0)
		{
			divisors.push_back(g);

			if(g * g != k) divisors.push_back(k / g);
		}
	}

	if(k != 1) divisors.push_back(k);
}