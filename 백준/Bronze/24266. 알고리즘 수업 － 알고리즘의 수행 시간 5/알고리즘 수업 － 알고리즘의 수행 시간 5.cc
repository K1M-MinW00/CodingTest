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

long long answer = 0;

void MenOfPassion(int n) {

	for (int i = 1; i <= n; ++i)
	{
		for (int j =  1; j <= n; ++j)
			for(int k=1;k<=n;++k)
				answer++;
	}

	return; // 코드1
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	MenOfPassion(n);

	cout << answer << '\n' << 3;

	return 0;
}