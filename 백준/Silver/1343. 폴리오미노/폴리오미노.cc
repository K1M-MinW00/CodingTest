#include <iostream>
#include <vector>
using namespace std;

int cnt_A = 0, cnt_B = 0;

void solve(int n)
{
	cnt_A = (n / 4);

	if (n % 4 != 2 && n % 4 != 0)
		cnt_B = -1;
	else
		cnt_B = (n % 4) / 2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int len = 0;
	vector<int> v;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
		{
			if (len != 0)
				v.push_back(len);

			v.push_back(0);
			len = 0;
		}
		else
			++len;
	}
	if (len != 0)
		v.push_back(len);

	string answer;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == 0)
			answer += '.';
		else
		{
			solve(v[i]);

			if (cnt_B == -1)
			{
				answer = "-1";
				break;
			}

			for (int j = 0; j < cnt_A; ++j)
				answer += "AAAA";

			for (int j = 0; j < cnt_B; ++j)
				answer += "BB";

			cnt_A = 0;
			cnt_B = 0;
		}
	}

	cout << answer;
	return 0;
}