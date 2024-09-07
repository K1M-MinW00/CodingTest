#include <iostream>
#include <string>
#include <cmath>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string str;
	long long m = 1234567891;
	long long r = 1;

	cin >> str;

	long long sum = 0;

	for (int i = 0; i < N; ++i)
	{
		sum += ((long(str[i]) - 96) * r) % m;
		r = (r * 31) % m;
	}

	cout << sum % m;

	return 0;
}