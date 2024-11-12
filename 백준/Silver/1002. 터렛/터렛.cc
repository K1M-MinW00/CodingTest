#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int x1, x2, y1, y2, r1, r2;

	while (n--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		int intersect_r = (r1 - r2) * (r1 - r2); // 두 반지름의 차
		int union_r = (r1 + r2) * (r1 + r2); // 두 반지름의 합

		if (d == 0) // 두 원의 중심이 일치
		{
			if (intersect_r == 0) // 반지름도 일치
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
		else
		{
			if (d == intersect_r || d == union_r) // 내접 || 외접
				cout << 1 << '\n';
			else if (intersect_r < d && d < union_r) // 두 점에서 만날 때
				cout << 2 << '\n';
			else
				cout << 0 << '\n';
		}
	}

	return 0;
}