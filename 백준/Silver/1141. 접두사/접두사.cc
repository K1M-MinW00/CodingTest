#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int answer = n;

	for (int i = 0; i < n - 1; ++i)
	{
		string temp = v[i + 1].substr(0, v[i].length());

		if (temp == v[i])
			answer--;
	}

	cout << answer;
	return 0;
}