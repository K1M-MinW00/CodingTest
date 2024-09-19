#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	string temp;
	int answer = 0;
	bool sub = false;

	for (int i = 0; i <= str.length(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			temp += str[i];

		else
		{
			int num = stoi(temp);
			temp = "";

			if (sub)
				answer -= num;
			else
				answer += num;

			if (str[i] == '-')
				sub = true;
		}
	}

	cout << answer;
	return 0;
}
