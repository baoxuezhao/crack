#include <iostream>

using namespace std;

int getNumberOf2(int num)
{
    int power = 1, count = 1;
	while(num / power >= 10)
	{
		power *= 10;
		count++;
	}
	int sum = 0;
	int prev = 0;
	while(count > 0)
	{
		int digit = num/power;
		if(digit > 2)
			sum += (prev+1)*power;
		else if(digit == 2)
			sum += (prev*power + (num%power+1));
		else
			sum += prev*power;
		
		prev = prev*10+digit;
		num = num % power;
		power /= 10;
		count--;
	}
	return sum;
}

int main()
{
	int num;
	cin >> num;
   	cout << getNumberOf2(num) << endl; 
    return 0;
}
