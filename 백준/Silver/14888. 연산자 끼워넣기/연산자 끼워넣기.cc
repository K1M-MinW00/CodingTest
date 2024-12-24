#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int cnt[4];
int a[12];
int maxV = -1000000000;
int minV = 1000000000;

void solve(int cur, int idx)
{
	if (idx == n - 1)
	{
		if (maxV < cur)
			maxV = cur;
		if (minV > cur)
			minV = cur;
		return;
	}

	int num = a[idx + 1];
	int before = cur;
	int temp;

	for (int j = 0; j < 4; ++j)
	{
		if (cnt[j] == 0)
			continue;

		temp = before;;

		cnt[j]--;

		if (j == 0)
		{
			temp += num;
			solve(temp, idx + 1);
		}
		else if (j == 1)
		{
			temp -= num;
			solve(temp, idx + 1);
		}
		else if (j == 2)
		{
			temp *= num;
			solve(temp, idx + 1);
		}
		else
		{
			if (temp < 0)
			{
				temp *= -1;
				temp /= num;
				temp *= -1;

				solve(temp, idx + 1);

			}
			else
			{
				temp /= num;
				solve(temp, idx + 1);
			}
		}
		cnt[j]++;
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < 4; ++i)
		cin >> cnt[i];

	int temp;
	int num = a[1];

	for (int j = 0; j < 4; ++j)
	{
		temp = a[0];

		if (cnt[j] == 0)
			continue;

		cnt[j]--;

		if (j == 0)
		{
			temp += num;
			solve(temp, 1);
		}
		else if (j == 1)
		{
			temp -= num;
			solve(temp, 1);
		}
		else if (j == 2)
		{
			temp *= num;
			solve(temp, 1);
		}
		else
		{
			temp /= num;
			solve(temp, 1);
		}
		cnt[j]++;
	}

	cout << maxV << '\n';
	cout << minV << '\n';
	return 0;
}