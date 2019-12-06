///
/// @file		1001__A+B_Format.cc
/// @author		fjd(clamfjd@gmail.com)
/// @date		2019-11-19 20:15:59
///

#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;

namespace fjd
{
stack<int> sta;

void calcu()
{
	int a, b; // || <= 10^6
	cin >> a >> b;
	int c = a + b;			// ||  /1000 /1000000  TODO
	if(0 == c)
	{
		cout << c << endl;
		return;
	}

	if (c < 0)
	{
		cout << '-';
		c = -c;
	}
	while(c)
	{
		sta.push(c % 10);
		c /= 10;
	}
	int digs = sta.size();
	int k = digs / 3;
	int l = digs % 3;
	for (int i = 0; i != l; ++i)
	{
		cout << sta.top();
		sta.pop();
	}
	if (k > 0 && l > 0)
	{
		cout << ',';
	}
	for (int i = 0; i != k; ++ i)
	{
		for (int j = 0; j != 3; ++ j)
		{
			cout << sta.top();
			sta.pop();
		}
		if (!sta.empty())
		{
			cout << ',';
		}
	}

	cout << endl;
}

}	// namespace fjd

using namespace fjd;



int main()
{
	calcu();
	return 0;
}

