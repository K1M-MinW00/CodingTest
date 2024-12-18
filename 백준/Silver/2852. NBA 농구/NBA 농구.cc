#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void print(int sum)
{
	string m = "00" + to_string(sum / 60);
	string s = "00" + to_string(sum % 60);

	string answer = m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
	cout << answer << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int t;
	string str;
	int m, s;
	int before = 0;
	int score1 = 0, score2 = 0;
	int sum1 = 0, sum2 = 0;

	while (n--)
	{
		cin >> t >> str;
		m = stoi(str.substr(0, 2));
		s = stoi(str.substr(3, 2));

		int cur = m * 60 + s;

		if (score1 > score2)
			sum1 += cur - before;
		else if (score1 < score2)
			sum2 += cur - before;

		if (t == 1)
			score1++;
		else
			score2++;

		before = cur;
	}

	int max = 48 * 60;

	if (score1 > score2)
		sum1 += max - before;
	else if (score1 < score2)
		sum2 += max - before;

	print(sum1);
	print(sum2);
	return 0;
}