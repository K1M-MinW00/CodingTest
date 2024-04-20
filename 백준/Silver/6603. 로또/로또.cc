#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int k;
	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		vector<int> s(k, 0);
		vector<int> tmp(k, 0);

		for (int i = 0; i < 6; ++i)
			tmp[i] = 1;

		for (int i = 0; i < k; ++i)
			cin >> s[i];


		do {
			for (int i = 0; i < k; ++i)
				if (tmp[i] == 1)
					cout << s[i] << ' ';
			cout << endl;
		} while (prev_permutation(tmp.begin(), tmp.end()));

		cout << endl;
	}

	return 0;
}