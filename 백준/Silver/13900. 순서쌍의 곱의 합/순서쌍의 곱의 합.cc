#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	v.resize(n);

	long long sumSquare = 0;
	long long squareSum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		squareSum += v[i] * v[i];
		sumSquare += v[i];
	}

	sumSquare *= sumSquare;

	long long answer = (sumSquare - squareSum) / 2;

	cout << answer;
	return 0;
}