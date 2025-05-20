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
	int i = n/2;
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

	cout << answer << '\n' << 0;

	return 0;
}