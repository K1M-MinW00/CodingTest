#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string l, r;
	cin >> l >> r;

	int n = min(l.length(), r.length());


	int answer = 0;

	if (l.length() == r.length())
	{
		for (int i = 0; i < l.length(); ++i)
		{
			if (l[i] == r[i] && l[i] == '8')
				answer++;
			else if (l[i] != r[i])
				break;
		}
	}

	cout << answer;

	return 0;
}