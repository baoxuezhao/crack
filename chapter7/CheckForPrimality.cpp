bool isPrime(int n)
{
	f(n < 2) return false;
	int sqare = (int)sqrt(n);
 
 	for(int i=2; i<=sqare; i++)
 	{
 		if(n%i == 0)
 			return false;
 	}
 	return true;
}
