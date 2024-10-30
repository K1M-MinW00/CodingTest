#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	int cnt = 0;
	cin >> n >> k;
	vector<int> p(n + 1);

	for (int i = 2; i <= n; i++)
	{
		p[i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			if (p[j] != 0)
			{
				p[j] = 0;
				cnt++;
				if (cnt == k)
				{
					cout << j << '\n';
					return 0;
				}
			}
		}
	}
	return 0;
}