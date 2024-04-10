#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> zero(n + 1, 0);
	vector<long long> one(n + 1, 0);

	one[1] = 1;
	zero[1] = 0;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 2; i <= n; ++i)
	{
		one[i] = zero[i - 1];
		zero[i] = zero[i - 1] + one[i - 1];
	}

	cout << one[n] + zero[n];

	return 0;
}