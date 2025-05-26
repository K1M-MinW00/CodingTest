#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <unordered_map>
using namespace std;

struct t {
	int r, c, s;
};

int A[51][51];


vector<t> op;
int n, m, k;

int calculate(int(&v)[51][51])
{
	int ret = 987654321;

	for (int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= m; ++j)
		{
			sum += v[i][j];
		}

		ret = min(ret, sum);
	}

	return ret;
}


void _rotate(int(&v)[51][51], int r, int c, int s)
{
	for (int i = 1; i <= s; ++i)
	{
		int top = r - i;
		int bottom = r + i;
		int left = c - i;
		int right = c + i;

		int prev = v[top][left];

		for (int j = left + 1; j <= right; ++j)
			swap(v[top][j], prev);

		for (int j = top + 1; j <= bottom; ++j)
			swap(v[j][right], prev);

		for (int j = right - 1; j >= left; --j)
			swap(v[bottom][j], prev);

		for (int j = bottom - 1; j >= top; --j)
			swap(v[j][left], prev);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	op.resize(k);
	vector<int> num(k);

	for (int i = 0; i < k; ++i)
		num[i] = i;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cin >> A[i][j];
	}

	for (int i = 0; i < k; ++i)
		cin >> op[i].r >> op[i].c >> op[i].s;

	int answer = 987654321;

	do
	{
		int v[51][51];
		memcpy(v, A, sizeof(A));

		for (int i = 0; i < k; ++i)
		{
			int r = op[num[i]].r;
			int c = op[num[i]].c;
			int s = op[num[i]].s;

			_rotate(v, r, c, s);
		}

		answer = min(answer, calculate(v));

	} while (next_permutation(num.begin(), num.end()));


	cout << answer;

	return 0;
}