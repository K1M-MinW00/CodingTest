#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s(100000);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	sort(s.begin(), s.end(),greater<int>());

	int max = 0, cur;

	for (int i = 0; i < n; ++i)
	{
		cur = s[i] * (i + 1);
		if (max < cur)
			max = cur;
	}

	cout << max;
	return 0;
}
