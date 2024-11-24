#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k;
vector<bool> visited(10, false);
vector<char> v;
vector<string> answer;

void solve(int before, int idx, string cur)
{
	if (idx == k)
	{
		answer.push_back(cur);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (visited[i])
			continue;

		string temp = cur;
		temp += (i + '0');
		if (v[idx] == '<')
		{
			int next = i;
			if (before < next)
			{
				visited[i] = true;
				solve(i, idx + 1, temp);
				visited[i] = false;
			}
		}
		else
		{
			int next = i;
			if (before > next)
			{
				visited[i] = true;
				solve(i, idx + 1, temp);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;

	v.resize(k);

	for (int i = 0; i < k; ++i)
		cin >> v[i];

	for (int i = 0; i < 10; ++i)
	{
		visited[i] = true;
		solve(i, 0, to_string(i));
		visited[i] = false;
	}

	sort(answer.begin(), answer.end());

	cout << answer.back() << '\n' << answer[0];

	return 0;
}