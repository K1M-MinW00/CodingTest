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
#include <tuple>
using namespace std;

int n;
pair<long long, long long> v[100001];
long long total = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
		total += v[i].second;
	}

	sort(v + 1, v + n + 1);

	long long temp = 0;

	for (int i = 1; i <= n; ++i)
	{
		temp += v[i].second;
		if (temp >= (total + 1) / 2)
		{
			cout << v[i].first;
			break;
		}
	}

	return 0;
}