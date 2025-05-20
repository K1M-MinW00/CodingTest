#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	if (a == 60 && b == 60 && c == 60)
		cout << "Equilateral";

	else if (a + b + c == 180)
	{
		if (a == b || a == c || b == c)
			cout << "Isosceles";
		else
			cout << "Scalene";
	}
	else
		cout << "Error";

	return 0;
}