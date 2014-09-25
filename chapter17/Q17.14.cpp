//target, min number of unrecognized characters.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//target, min number of unrecognized characters.
vector<int> minUnrecoginized(string str, unordered_set<string> dict)
{
	const int len = str.size();

	vector<vector<bool> > contains(len, vector<bool>(len, false));
	vector<int> f(len+1, 0);
	vector<int> prev(len, -1);

	for(int i=0; i<len; i++)
	{
		for(int j=i; j<len; j++)
		{
			contains[i][j] = dict.count(str.substr(i, j-i+1))>0;
		}
	}

	prev[0] = -1;

	for(int i=0; i<len; i++)
	{
		f[i+1] = (contains[0][i]?0:(i+1));
		for(int j=-1; j<i; j++)
		{
			int tmp = f[j+1] + ((contains[j+1][i]==true)? 0:(i-j));
			if(tmp < f[i+1])
			{
				f[i+1] = tmp;
				prev[i] = j;
			}
		}
	}
	cout << f[len] << endl;
	return prev;
}

int main()
{
	string s = "jesslookedjustliketimherbrother";

	unordered_set<string> dict;
	dict.insert("looked");
	dict.insert("just");
	dict.insert("like");
	dict.insert("her");
	dict.insert("brother");

	vector<int> prev = minUnrecoginized(s, dict);
	int end = s.length()-1;

	while(end >= 0)
	{
		cout << s.substr(prev[end]+1, end-prev[end]) << endl;
		end = prev[end];
	}

	return 0;
}
