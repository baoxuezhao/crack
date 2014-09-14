#include <iostream>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int> &s)
{
	stack<int> t;

	while(!s.empty())
	{
		int tmp = s.top();
		s.pop();
		while(!t.empty() && t.top() > tmp)
		{
			s.push(t.top());
			t.pop();
		}
		t.push(tmp);
	}
	return t;
}

int main() {

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(0);
	s.push(6);
	s.push(8);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(5);
	s.push(1);
	s.push(10);

	stack<int> t = sortStack(s);
	while(!t.empty())
	{
		cout << t.top() << " ";
		t.pop();
	}
	return 0;
}
