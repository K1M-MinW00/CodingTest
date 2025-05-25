#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int sum = 0, card;
	set<int> s;
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		cin >> card;
		sum += card;

		v.push_back(card);

		for (int num : s)
			v.push_back(card + num);

		s.insert(v.begin(), v.end());
		v.clear();
	}

	cout << sum - s.size();

	return 0;
}