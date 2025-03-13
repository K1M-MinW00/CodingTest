#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> charge(n + 1);
	vector<int> weight(m + 1);

	for (int i = 1; i <= n; ++i)
		cin >> charge[i];

	for (int i = 1; i <= m; ++i)
		cin >> weight[i];

	int op;
	queue<int> wait; // 대기 차량 번호
	vector<int> p(n + 1); // 주차장
	int p_cnt = 0; // 주차장 차 있는 자리
	int answer = 0;
	int p_idx = 0;


	for (int i = 0; i < m * 2; ++i)
	{
		cin >> op;

		if (op > 0) // 차량 진입
		{
			if (p_cnt < n) // 주차장 남는 자리
			{
				for (int j = 1; j <= n; ++j)
				{
					if (p[j] == 0)
					{
						p_idx = j;
						p[j] = op; // 주차
						p_cnt++;
						break;
					}
				}
				answer += (charge[p_idx] * weight[op]); // 주차 요금 * 무게
			}
			else
			{
				wait.push(op); // 대기
			}
		}
		else // 차량 출차
		{
			op *= -1;

			for (int j = 1; j <= n; ++j)
			{
				if (p[j] == op)
				{
					p[j] = 0;
					p_cnt--;
					break;
				}
			}

			if (wait.size()) // 대기 차량이 있는 경우
			{
				int first = wait.front();
				wait.pop();


				for (int j = 1; j <= n; ++j)
				{
					if (p[j] == 0)
					{
						p_idx = j;
						p[j] = first; // 주차
						p_cnt++;
						break;
					}
				}

				answer += (charge[p_idx] * weight[first]); // 주차 요금 * 무게
			}
		}
	}


	cout << answer;
	return 0;
}