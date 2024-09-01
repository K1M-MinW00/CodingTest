#include <iostream>

using namespace std;

int main()
{
	int A, K;

	cin >> A >> K;

	int answer = 0;

	while (1)
	{
		if (A == K)
			break;

		if (K % 2 == 0 && (K / 2) >= A)
			K /= 2;
		else
			K -= 1;

		answer++;
	}

	cout << answer;
	return 0;
}