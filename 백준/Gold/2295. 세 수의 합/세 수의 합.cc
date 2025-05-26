#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <unordered_map>
using namespace std;

vector<int> v, sum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			sum.push_back(v[i] + v[j]);
		}
	}

	sort(v.begin(), v.end());
	sort(sum.begin(), sum.end());


	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j >= 0; --j)
		{
			int a = v[i] - v[j];
			bool exist = binary_search(sum.begin(), sum.end(), a);

			if (exist)
			{
				cout << v[i] << '\n';
				return 0;
			}
		}
	}

	return 0;
}