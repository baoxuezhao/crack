#include <iostream>
using namespace std;

//we assume a <= b
int computeGCD(int a, int b)
{
	if(a > b)
		return computeGCD(b, a);
	
	while(a)
	{
		int t = b%a;
		a = t;
		b = a;
	}
	return b;
}

int main()
{
	cout << computeGCD(1, 1)   << endl;
	cout << computeGCD(54, 24) << endl;
	cout << computeGCD(89, 97) << endl;
	cout << computeGCD(24, 72) << endl;
	cout << computeGCD(72, 24) << endl;
	
	return 0;
}
