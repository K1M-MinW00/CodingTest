#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int s, k;
	cin >> s >> k;

	int tmp1 = s / k;
	int tmp2 = s % k;

	long long answer = 1;
	for (int i = 0; i < k; ++i)
	{
		if (tmp2 > 0)
		{
			answer *= (tmp1 + 1);
			tmp2--;
		}
		else
			answer *= tmp1;
	}

	cout << answer;

}