#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int size[6];
	cin >> size[0] >> size[1] >> size[2] >> size[3] >> size[4] >> size[5];

	int T, P;
	cin >> T >> P;

	int answer_T = 0;

	for (int i = 0; i < 6; ++i)
	{
		answer_T += (size[i] / T);

		if (size[i] % T > 0)
			answer_T += 1;
	}

	int answer_P1 = N / P;
	int answer_P2 = N % P;

	cout << answer_T << '\n';
	cout << answer_P1 << ' ' << answer_P2;

	return 0;
}