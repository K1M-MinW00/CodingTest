#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int hs(int n)
{
	int answer = n;

	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;

		answer = max(answer, n);
	}
	return answer;
}
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
		cout << hs(n) << '\n';
	}
	return 0;
}