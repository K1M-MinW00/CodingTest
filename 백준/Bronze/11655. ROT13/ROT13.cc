#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);

	string answer;

	for (int i = 0; i < s.length(); ++i)
	{
		char c = s[i];
		if (isupper(c))
			answer += (char)((s[i] - 'A' + 13) % 26 + 'A');
		else if (islower(c))
			answer += (char)((s[i] - 'a' + 13) % 26 + 'a');
		else
			answer += c;
	}

	cout << answer;

	return 0;
}