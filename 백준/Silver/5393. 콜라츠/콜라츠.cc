#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;

	int n;
	while (t--)
	{
		cin >> n;
		int answer = 0;

		if (n % 2 == 0)
			answer += n / 2;
		else
			answer += n / 2 + 1;

		if (n % 6 == 0 || n % 6 == 4)
			answer += n / 3;
		else
			answer += n / 3 + 1;

		cout << answer << '\n';
	}
	return 0;
}