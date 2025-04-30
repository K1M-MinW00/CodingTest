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

using namespace std;
#define MAX 501

int h, w;
int v[MAX];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> h >> w;

	for (int i = 0; i < w; ++i)
		cin >> v[i];

	int answer = 0;

	for (int i = 1; i < w - 1; ++i)
	{
		int left = 0, right = 0;

		for (int j = 0; j < i; ++j)
			left = max(left, v[j]);

		for (int j = w - 1; j > i; --j)
			right = max(right, v[j]);

		int m = min(left, right);

		answer += max(0, m - v[i]);
	}

	cout << answer;

	return 0;
}