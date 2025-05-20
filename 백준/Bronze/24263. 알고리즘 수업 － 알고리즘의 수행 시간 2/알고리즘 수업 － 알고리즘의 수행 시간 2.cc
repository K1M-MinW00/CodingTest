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
int answer = 0;

int MenOfPassion(int n) {
	int sum = 0;

	for (int i = 1; i <= n; ++i)
		answer++;
	
	return 1 ; // 코드1
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	MenOfPassion(n);

	cout << answer << '\n' << 1;

	return 0;
}