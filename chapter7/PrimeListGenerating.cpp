void primeListGenerating(int n)
{
	bool isPrime[n+1];
	
	for(int i=2; i<n+1; i++)
		isPrime[i] = true;
	
	int prime = 2;
	while(prime <= sqrt(n))
	{
		for(int cur = prime*prime; cur < n+1; cur += prime)
			isPrime[cur] = false;
		
		for(int cur = prime+1; cur < n+1; cur++)
		{
			if(isPrime[cur])
			{
				prime = cur;
				break;
			}
		}
	}
}
