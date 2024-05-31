#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;

	cin >> a >> b;

	int la = a.length(), lb = b.length(), cnt = 0, minV = 50;

	for (int i = 0; i <= lb - la; ++i)
	{
		cnt = 0;

		for (int j = 0; j < la; ++j)
		{
			if (a[j] != b[i + j]) cnt++;
		}

		minV = min(minV, cnt);
	}

	cout << minV;
}