#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; ++test_case)
	{
		int H, W, N;

		cin >> H >> W >> N;

		int h = N % H;
		if (h == 0)
			h = H;
		int w = (N-1) / H + 1;

		string answer;
		if (w < 10)
			answer = to_string(h) + "0" + to_string(w);
		else
			answer = to_string(h) + to_string(w);

		cout << answer << '\n';
	}

	return 0;
}