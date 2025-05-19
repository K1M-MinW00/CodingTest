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

	int n;
	cin >> n;

	vector<int> cx(n),cy(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> cx[i] >> cy[i];
	}

	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());

	int maxx = cx.back();
	int minx = cx.front();

	int maxy = cy.back();
	int miny = cy.front();

	cout << (maxx - minx) * (maxy - miny);

	return 0;
}