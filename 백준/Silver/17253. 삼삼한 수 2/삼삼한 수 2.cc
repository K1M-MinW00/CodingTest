#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	bool isSamSam = true;

	if (n == 0)
	{
		cout << "NO";
		return 0;
	}

	while (n)
	{
		int remainder = n % 3;
		if (remainder > 1)
		{
			isSamSam = false;
			break;
		}
		n /= 3;
	}

	if (isSamSam)
		cout << "YES";
	else
		cout << "NO";

	return 0;

}