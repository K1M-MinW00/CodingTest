#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, r, c;
int idx;


void solve(int x, int y, int size)
{
	if (r == x && c == y)
	{
		cout << idx << '\n';
		return;
	}

    // (r,c) 가 현재 좌표 (x,y) 와 같은 사분면에 있을 때
	if (r < x + size && r >= x && c < y + size && c >= y)
	{
		solve(x, y, size / 2);
		solve(x, y + size / 2, size / 2);
		solve(x + size / 2, y, size / 2);
		solve(x + size / 2, y + size / 2, size / 2);
	}
	else // 다른 사분면에 있을 때, 현재 사분면의 크기만큼 더해준다.
		idx += size * size;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> c;

	solve(0, 0, (1 << n));

	return 0;
}