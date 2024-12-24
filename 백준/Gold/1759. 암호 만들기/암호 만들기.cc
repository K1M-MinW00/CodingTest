#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
char a[16];
vector<string> answer;

void solve(int idx, string temp, int parent, int child)
{
	if (temp.size() == l)
	{
		if (parent >= 1 && child >= 2)
			answer.push_back(temp);
		return;
	}

	for (int i = idx + 1; i < c; ++i)
	{
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			parent++;
		else
			child++;
		temp.push_back(a[i]);
		solve(i, temp, parent, child);
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			parent--;
		else
			child--;
		temp.pop_back();
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; ++i)
		cin >> a[i];

	sort(a, a + c);

	string temp;
	int parent = 0, child = 0;

	for (int i = 0; i < c; ++i)
	{
		parent = 0;
		child = 0;
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			parent++;
		else
			child++;

		temp.push_back(a[i]);
		solve(i, temp, parent, child);
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			parent--;
		else
			child--;
		temp.pop_back();
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';

	return 0;
}