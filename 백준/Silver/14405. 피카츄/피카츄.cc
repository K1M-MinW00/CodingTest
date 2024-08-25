#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	bool answer = true;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == 'p' && str[i + 1] == 'i')
			i += 1;
		else if (str[i] == 'k' && str[i + 1] == 'a')
			i += 1;

		else if (str[i] == 'c' && str[i + 1] == 'h' && str[i + 2] == 'u')
			i += 2;
		else
		{
			answer = false;
			break;
		}
	}

	if (answer)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}