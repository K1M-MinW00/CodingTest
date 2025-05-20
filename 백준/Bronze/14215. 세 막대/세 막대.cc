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
	
	int sum = a + b + c;
	int maxx = max(max(a, b), c);

	int two = sum - maxx;

	cout << two + min(maxx, two - 1);
	
	return 0;
}