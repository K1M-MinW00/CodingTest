#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	getline(cin, str);

	string ucpc = "CPCU";
	int idx = 0;

	for (int i = str.length() - 1; i >= 0; --i)
	{
		if (str[i] == ucpc[idx])
		{
			idx++;
		}
	}

	if (idx == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
	return 0;
}