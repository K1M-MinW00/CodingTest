#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int answer = n;


	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		bool alpha[26] = { false, };
		alpha[(int)(str[0] - 'a')] = true;

		for (int j = 1; j < str.length(); ++j)
		{
			if (str[j] == str[j - 1])
				continue;

			else
			{
				if (alpha[(int)(str[j] - 'a')] == false)
					alpha[(int)(str[j] - 'a')] = true;

				else
				{
					answer--;
					break;
				}
			}
		}
	}
	cout << answer;

	return 0;
}