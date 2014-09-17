//Method 1:
//copied from others
int getKthNum(int k)
{
	if(k == 0)
		return 0;
	queue<int> Q3;
	queue<int> Q5;
	queue<int> Q7;
	Q3.push(1);
	int val = INT_MAX;
	for(int i = 0; i <=k;++i)
	{
		int v3 = Q3.size() == 0?INT_MAX:Q3.front();
		int v5 = Q5.size() == 0?INT_MAX:Q5.front();
		int v7 = Q7.size() == 0?INT_MAX:Q7.front();
		val = min(v3,min(v5,v7));
		if(val == v3)
		{
			Q3.pop();
			Q3.push(val*3);
			Q5.push(val*5);
		}
		else if(val == v5)
		{
			Q5.pop();
			Q5.push(val*5);
		}
		else if(val == v7)
		{
			Q7.pop();
		}
		Q7.push(val*7);
	}
	return val;
}

//method 2, from geeksforgeeks
int uglyNumber(int k)
{
	int count2 = 0;
	int count3 = 0;
	int count5 = 0;

	if(k == 1) return 1;

	vector<int> result;
	result.push_back(1);
	int cur = 0;

	for(int i=1; i<k; i++)
	{
		cur = std::min(result[count2]*3, std::min(result[count3]*5, result[count5]*7));
		result.push_back(cur);
		if(cur == result[count2]*3)
			count2++;

		if(cur == result[count3]*5)
			count3++;

		if(cur == result[count5]*7)
			count5++;
	}
	return cur;
}






