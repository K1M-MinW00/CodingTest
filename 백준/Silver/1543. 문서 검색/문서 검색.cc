#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;

	getline(cin, a);
	getline(cin, b);

	int answer = 0;
	int idx = 0;
	int before;
	for (int i = 0; i < a.length(); ++i)
	{
		if (idx == 0)
			before = i + 1;

		if (a[i] == b[idx])
		{
			idx++;
			if (idx == b.length())
			{
				answer++;
				idx = 0;
			}
		}
		else
		{
			idx = 0;
			i = before - 1;
		}
	}

	cout << answer;

	return 0;
}