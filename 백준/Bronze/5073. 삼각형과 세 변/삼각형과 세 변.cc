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

	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (!a && !b && !c)
			break;

		int sum = a + b + c;
		int maxx = max(max(a, b), c);
		
		if (maxx >= sum - maxx)
			cout << "Invalid";

		else if (a == b && b == c)
			cout << "Equilateral";

		else if (a == b || a == c || b == c)
			cout << "Isosceles";
		
		else if (a != b && b != c && a != c)
			cout << "Scalene";
		else
			cout << "Invalid";

		cout << '\n';
	}
	return 0;
}