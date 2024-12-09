#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int a[26] = { 0 };


	string name;
	for (int i = 0; i < n; ++i)
	{
		cin >> name;
		a[name[0] - 'a']++;
	}

	string answer;
	for (int i = 0; i < 26; ++i)
		if (a[i] >= 5)
			answer += (char)(i + 'a');

	if (answer != "")
		cout << answer;
	else
		cout << "PREDAJA";
	return 0;
}