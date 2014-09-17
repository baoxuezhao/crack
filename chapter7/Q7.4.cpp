//Write methods to implement the multiply, subtract, and divide operations for integers. Use only the add operator.

//flip the integer sign
int neglate(int a)
{
	int delta = (a>0)?(-1): 1;
	
	int neg = 0;
	while(a != 0)
	{
		a += delta;
		neg += delta;
	}
	return neg;
}

int abs(int a)
{
	if(a < 0) 
		return neglate(a);
	else
		return a;
}

//subtract b from a
int subtract(int a, int b)
{
	return a + neglate(b);
}

//multiply a and b
int multiply(int a, int b)
{
	if(a < b) 
		return multiply(b, a);
	
	int absb = abs(b);
	
	int product = 0;
	for(int i=0; i<absb; i++)
	{
		product += a;
	}
	
	if(b > 0)
		return product;
	else
		return neglate(product);
}

//divide a by b
int divide(int a, int b)
{
	if(b == 0)
	{
		cout << "ERROR" << endl;
		return INT_MAX;
	}
	
	int absa = abs(a);
	int absb = abs(b);
	
	int product = 0;
	int result = 0;
	while(product + absb <= absa)
	{
		product += absb;
		result++;
	}
	
	if((a > 0 && b > 0) || (a < 0 && b < 0))
		return result;
	else
		return neglate(result);
}
