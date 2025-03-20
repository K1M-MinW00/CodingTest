#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, p;
	cin >> a >> p;

	map<int, int> m;

	int d = a;
	int idx = 1;
	m.insert({ d,idx });

	while (1)
	{
		string str = to_string(d);

		d = 0;

		for (int i = 0; i < str.length(); ++i)
			d += pow(str[i] - '0', p);

		if (m.find(d) == m.end())
			m.insert({ d,++idx });

		else
			break;
	}

	cout << m[d] - 1;


	return 0;
}