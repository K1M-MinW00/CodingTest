#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> info;

	for (int i = 0; i < n; ++i)
	{
		int h, w;

		cin >> w >> h;
		info.push_back({ w,h });
	}

	vector<int> answer;

	for (int i = 0; i < n; ++i)
	{
		int rank = 1;

		for (int j = 0; j < n; ++j)
		{
			if (info[i].first < info[j].first && info[i].second < info[j].second)
				rank++;
		}

		cout << rank << '\n';
	}

	return 0;
}