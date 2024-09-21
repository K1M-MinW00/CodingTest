#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; ++i)
	{
		int s, e;
		cin >> s >> e;
		v[i] = { e,s };
	}

	sort(v.begin(), v.end());

	int answer = 0, end = 0;

	for (int i = 0; i < n; ++i)
	{
		if (v[i].second >= end) // 다음 회의 시작 시간 >= 현재 시간
		{
			end = v[i].first; // 현재 시간 = 다음 회의 종료 시간
			answer++;
		}
	}

	cout << answer;

	return 0;
}