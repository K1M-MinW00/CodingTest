#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

deque<int> dq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		dq.push_back(i);

	for (int i = 1; i < n; ++i)
	{
		long long t = pow(i, 3); // i 단계 : i^3 

		t--;
		t %= (n - i + 1); // 남은 인원 수로 나눠지는 턴

		while (t--)
		{
			dq.push_back(dq.front());
			dq.pop_front();
		}
		dq.pop_front(); // 사람 제거 후, 앞으로 이동
	}

	cout << dq.front();

	return 0;
}