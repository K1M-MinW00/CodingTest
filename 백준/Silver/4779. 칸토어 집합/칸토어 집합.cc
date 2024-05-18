#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

	vector<string> str(13);
	str[0]= "-";

	for (int i = 1; i <= 12; ++i)
	{
		string before = str[i - 1];
		string tmp = before;
		int before_length = str[i - 1].length();
		for (int j = 0; j < before_length; ++j)
			tmp += " ";
		tmp += before;

		str[i] = tmp;
	}

	int n;

	while (cin >> n)
	{
		cout << str[n] << '\n';
	}

	return 0;
}