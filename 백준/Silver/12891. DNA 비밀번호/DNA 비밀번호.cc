#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

int n, m, answer, chk;
int condition[4], cnt[4];

string str;

void check()
{
	for (int i = 0; i < 4; ++i)
		if (cnt[i] < condition[i])
			return;
	answer++;
}

void addChar(char c)
{
	switch (c)
	{
	case 'A':
		cnt[0]++;
		break;
	case'C':
		cnt[1]++;
		break;
	case 'G':
		cnt[2]++;
		break;
	case 'T':
		cnt[3]++;
		break;
	}
}
void subChar(char c)
{
	switch (c)
	{
	case 'A':
		cnt[0]--;
		break;
	case'C':
		cnt[1]--;
		break;
	case 'G':
		cnt[2]--;
		break;
	case 'T':
		cnt[3]--;
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> str;

	for (int i = 0; i < 4; ++i)
		cin >> condition[i];

	for (int i = 0; i < m; ++i)
		addChar(str[i]);

	check();

	for (int i = m; i < n; ++i)
	{
		subChar(str[i - m]);
		addChar(str[i]);
		check();
	}

	cout << answer;
	return 0;
}