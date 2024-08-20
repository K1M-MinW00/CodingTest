#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str;
	cin >> str;

	vector<int> alphabet(26, 0);
	vector<int> odd;

	for (int i = 0; i < str.length(); ++i)
	{
		alphabet[str[i] - 'A']++;
	}


	string front, end, answer;

	for (int i = 0; i < alphabet.size(); ++i)
	{
		if (alphabet[i] == 0)
			continue;

		for (int j = 1; j <= alphabet[i] / 2; ++j)
		{
			char c = (i + 'A');
			front += c;
		}
		if (alphabet[i] % 2 == 1)
			odd.push_back(i);
	}

	end = front;

	//cout << front << ' ' << end;
	if (odd.size() > 1)
		answer = "I'm Sorry Hansoo";

	else if (odd.size() == 1)
	{
		front += (odd[0] + 'A');
		reverse(end.begin(), end.end());
		answer = front + end;
	}
	else
	{
		reverse(end.begin(), end.end());
		answer = front + end;
	}

	cout << answer;
	return 0;
}