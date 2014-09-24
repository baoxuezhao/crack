#include <iostream>
#include <string>
using namespace std;

string convertThreeDigits(int num)
{
	string result;

	string digits[] = {"One", "Two", "Three", "Four", "Five",
			"Six", "Seven", "Eight", "Nine"};
	string teens[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
			"Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	string tens[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
			"Seventy", "Eighty", "Ninety"};

	if(num >= 100)
	{
		result += digits[num/100-1] + " Hundred ";
		num = num%100;
	}

	if(num >= 11 && num <= 19)
	{
		result += teens[num-11] + " ";
		return result;
	}
	else if(num == 10 || num >= 20)
	{
		result += (tens[num/10-1] + " ");
		num = num%10;
	}

	if(num >= 1 && num <= 9)
	{
		result += (digits[num-1] + " ");
	}
	return result;
}

string describInteger(int num)
{
	string result;
	string digits[] = {"One", "Two", "Three", "Four", "Five",
			"Six", "Seven", "Eight", "Nine"};
	string bigs[] = {"", "Thousand", "Million", "Billion"};
	if(num == 0)
		return "Zero";
	else
	{
		int count = 0;
		while(num > 0)
		{
			result = (convertThreeDigits(num%1000) + bigs[count] + " " + result);
			num /= 1000;
			count++;
		}
		return result;
	}
}


int main()
{
	cout << describInteger(19323984) << endl;
	return 0;
}
