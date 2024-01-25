bool isPrime[MAX];

void makeSieve()
{
	memset(isPrime, false, sizeof(isPrime));

	for(int g = 2; g <= N; g++)
	{
		if(!isPrime[g]) continue;

		for(int k = 2 * g; k <= N; k++)
			isPrime[k] = false;
	}
}