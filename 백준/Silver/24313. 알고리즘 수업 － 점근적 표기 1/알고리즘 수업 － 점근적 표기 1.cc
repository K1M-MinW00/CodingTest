#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a1,a2,c,n;
	cin >> a1 >> a2 >> c >> n;

	if (a1 <= c && a2 <= (c - a1) * n)
		cout << 1;
	else
		cout << 0;

	return 0;
}