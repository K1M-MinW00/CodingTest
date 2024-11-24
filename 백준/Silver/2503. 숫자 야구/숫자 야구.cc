#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<bool> num(1001, false);



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 123; i <= 987; ++i) // 123 ~ 987 까지, 같은 숫자가 2번 이상 들어가거나 0 이 들어가는 수를 제외하고 가능성이 있으므로 True 로 설정
	{
		string temp = to_string(i);

		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2] || temp[1] == '0' || temp[2] == '0')
			continue;

		num[i] = true;
	}

	int t;
	cin >> t;

	string input;
	int s, b;

	for (int i = 0; i < t; ++i)
	{
		cin >> input >> s >> b;

		for (int j = 123; j <= 987; ++j)
		{
			int s_cnt = 0, b_cnt = 0;

			if (!num[j])
				continue;

			string temp = to_string(j);

			for (int idx = 0; idx < 3; ++idx)
			{
				for (int temp_idx = 0; temp_idx < 3; ++temp_idx)
				{
					if (idx == temp_idx && input[idx] == temp[temp_idx])s_cnt++;
					if (idx != temp_idx && input[idx] == temp[temp_idx]) b_cnt++;
				}
			}
			if (s_cnt != s || b_cnt != b) num[j] = false;
		}
	}

	int cnt = 0;
	for (int i = 123; i <= 987; ++i)
		if (num[i])
			cnt++;

	cout << cnt;

	return 0;
}