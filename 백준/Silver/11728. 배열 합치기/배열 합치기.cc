#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;


	int x;

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		s.push_back(x);
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		s.push_back(x);
	}

	sort(s.begin(), s.end());

	for (auto x : s)
		cout << x << " ";

	return 0;
}