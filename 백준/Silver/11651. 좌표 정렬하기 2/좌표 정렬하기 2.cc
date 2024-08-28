#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> cor;

	int x, y;

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;

		cor.push_back(make_pair(y, x));
	}

	sort(cor.begin(), cor.end());

	for (int i = 0; i < n; ++i)
	{
		cout << cor[i].second << ' ' << cor[i].first << '\n';
	}

	return 0;
}