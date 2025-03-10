#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> v(n);
	vector<int> answer(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	sort(v.begin(), v.end());

	long long min_answer = LLONG_MAX;

	for (int left = 0; left < n - 2; ++left)
	{
		int mid = left + 1, right = n - 1;

		while (mid < right)
		{
			long long temp = v[left] + v[mid] + v[right];
			long long abs_temp = abs(temp);

			if (min_answer > abs_temp)
			{
				min_answer = abs_temp;
				answer[0] = v[left];
				answer[1] = v[mid];
				answer[2] = v[right];
			}

			if (temp < 0)
				mid++;
			else
				right--;
		}
	}

	cout << answer[0] << ' ' << answer[1] << ' ' << answer[2];
	return 0;
}