#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);


	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int answer = 0;
	int start = 0, end = 0;
	int sum = v[0];

	while (end < n)
	{
		if (sum == m)
		{
			answer++;
			sum += v[++end];
		}

		else if (sum < m)
			sum += v[++end];

		else
			sum -= v[start++];
	}

	cout << answer;

	return 0;
}