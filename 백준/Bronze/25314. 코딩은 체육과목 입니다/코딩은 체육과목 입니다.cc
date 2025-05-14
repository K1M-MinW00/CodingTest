#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int m = n / 4;

	for (int i = 0; i < m; ++i)
		cout << "long ";
	cout << "int";

	return 0;
}