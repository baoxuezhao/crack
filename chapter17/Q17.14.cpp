//target, min number of unrecognized characters.

#include <iostream>
#include <vector>
#include <unordered_set>

int minUnrecoginized(string str, unordered_set<string> dict)
{
	const int len = str.size();
	
	vector<vector<bool> > contains(len, vector<bool>(len, false));
	vector<int> f(len, 0);
	
	for(int i=0; i<len; i++)
	{
		for(int j=i; j<len; j++)
		{
			contains[i][j] = dict.contains(str.substr(i, j-i+1));
		}
	}
	
	for(int i=0; i<len; i++)
	{
		f[i] = contains[0][i]?0:(i+1);
		for(int j=0; j<i; j++)
		{
			int tmp = f[j] + contains[j+1][i]? 0:(i-j);
			f[i] = min(f[i], tmp);
		}
	}
	return f[len-1];
}
