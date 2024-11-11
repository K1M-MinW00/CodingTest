#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		s.insert(num);
	}

	for (auto e : s)
		cout << e << ' ';

	return 0;
}