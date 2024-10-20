#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long A[50];

	A[1] = 0;
	A[2] = 1;

	for (int i = 3; i <= n + 1; ++i)
	{
		A[i] = A[i - 1] + A[i - 2];
	}

	cout << A[n] << ' ' << A[n + 1];
	return 0;
}