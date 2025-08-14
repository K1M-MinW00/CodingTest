#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n;

	vector<int> crane(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> crane[i];
	}

	cin >> m;

	vector<int> box(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> box[i];
	}


	sort(crane.begin(), crane.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	int cnt = 0;


	if (crane[0] < box[0])
	{
		cout << -1;
		return 0;
	}


	while (box.size())
	{
		cnt++;
		for (int i = 0; i < crane.size(); ++i)
		{
			for (int j = 0; j < box.size(); ++j)
			{
				if (crane[i] >= box[j])
				{
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}