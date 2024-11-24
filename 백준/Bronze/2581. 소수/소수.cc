#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(m + 1, 0);

	vector<int> answer;

	for (int i = 2; i <= m; ++i)
	{
		if (v[i] == 0)
		{
			if (i >= n)
				answer.push_back(i);

			for (int j = i; j <= m; j += i)
			{
				if (v[j] == 0)
				{
					v[j] = 1;
				}
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < answer.size(); ++i)
	{
		sum += answer[i];
	}


	if (answer.size())
		cout << sum << '\n' << answer[0];
	else
		cout << -1;
	return 0;
}