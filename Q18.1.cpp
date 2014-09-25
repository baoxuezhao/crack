int add(int a, int b)
{
	if(b == 0) return a;
	
	int sum = a ^ b;
	int carry = (a & b) << 1;
	while(carry != 0)
	{
		int sum2 = sum ^ carry;
		int carry2 = (sum & carry) << 1;
		
		sum = sum2;
		carry = carry2;
	}
	return sum;
}
