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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int num;
	vector<pair<int, int>> score;

	for (int i = 1; i <= 8; ++i)
	{
		cin >> num;
		score.push_back({ num, i });
	}

	sort(score.begin(), score.end(), greater<pair<int, int>>());

	/*for (int i = 0; i < 8; ++i)
		cout << score[i].first << " " << score[i].second << '\n';*/

	int answer = 0;
	int idx[5];

	for (int i = 0; i < 5; ++i)
	{
		answer += score[i].first;
		idx[i] = score[i].second;
	}

	cout << answer << '\n';

	sort(idx, idx + 5);
	for (int i = 0; i < 5; ++i)
		cout << idx[i] << ' ';

	return 0;
}