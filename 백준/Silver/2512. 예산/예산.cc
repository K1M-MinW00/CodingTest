#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

int n, m;
vector<int> v;

int bin()
{
	int s = 0, e = v[n - 1];
	int answer, mid, sum = 0;

	while (s <= e)
	{
		mid = (s + e) / 2;
		sum = 0;

		for (int i = 0; i < n; ++i)
			sum += min(v[i], mid);


		if (m >= sum)
		{
			answer = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	return answer;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	cin >> m;

	cout << bin();

	return 0;
}