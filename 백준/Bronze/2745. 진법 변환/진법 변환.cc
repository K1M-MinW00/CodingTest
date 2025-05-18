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

int v[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string n;
	int b;

	cin >> n >> b;

	int answer = 0;

	for (int i = 0; i < n.length(); ++i)
	{
		char c = n[i];

		answer *= b;

		if (c >= '0' && c <= '9')
			answer += (c - '0');

		else
			answer += (c - 'A') + 10;
	}

	
	cout << answer;


	return 0;
}