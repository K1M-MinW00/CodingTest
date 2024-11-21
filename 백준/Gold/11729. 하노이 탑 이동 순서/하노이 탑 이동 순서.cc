#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int s, int e, int v)
{	
	if (n == 1)
	{
		cout << s << ' ' << e << '\n';
	}
	else
	{
		hanoi(n - 1, s, v, e);
		cout << s << ' ' << e << '\n';
		hanoi(n - 1, v, e, s);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	cout << (int)pow(2,n) -1<< '\n';
	hanoi(n, 1, 3, 2);
	return 0;
}