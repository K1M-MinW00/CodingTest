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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	int n, m;
	cin >> n >> m;

	vector<int> temp;

	for (int i = 0; i < n; ++i)
	{
		int p, l;
		cin >> p >> l;
		vector<int> v(p);

		for (int j = 0; j < p; ++j)
		{
			cin >> v[j];
		}

		if (p < l)
			temp.push_back(1);
		else
		{
			sort(v.begin(), v.end());
			temp.push_back(v[p - l]);
		}
	}

	sort(temp.begin(), temp.end());


	int sum = 0, cnt = 0;

	for (int i = 0; i < temp.size(); ++i)
	{
		sum += temp[i];

		if (sum <= m)
			cnt++;
		else
			break;
	}

	cout << cnt;
	return 0;
}