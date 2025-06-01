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
#define N 1000005

vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int answer = 0, cnt = 0;

	for (int i = 1; i < N; i <<= 1)
	{
		cnt = 0;

		for (int j = 0; j < n; ++j)
		{
			if (v[j] & i)
				cnt++;
		}

		answer = max(answer, cnt);
	}

	cout << answer;

	return 0;
}