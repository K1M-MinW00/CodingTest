#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	string str;
	cin >> str;

	int answer = 0;

	for (int i = 0; i < m; ++i)
	{
		int cnt = 0;

		if (str[i] != 'I')
			continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I')
		{
			cnt++;

			if (cnt == n)
			{
				answer++;
				cnt--;
			}
			i += 2;
		}
	}

	cout << answer;

	return 0;
}