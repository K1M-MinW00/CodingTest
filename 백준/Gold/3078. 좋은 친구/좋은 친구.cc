#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int v[600001];
int cnt[23] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	long long answer = 0;
	string name;

	for (int i = 0; i < n; ++i)
	{
		cin >> name;
		v[i] = name.length();
	}

	for (int i = 0; i <= k; ++i) // 1등부터 k등까지
		cnt[v[i]]++;

	for (int i = 0; i < n - 1; ++i)
	{
		cnt[v[i]]--; // 자신 제외

		answer += cnt[v[i]];
		cnt[v[i + k + 1]]++; // 다음 슬라이드로 이동
	}

	cout << answer;

	return 0;
}