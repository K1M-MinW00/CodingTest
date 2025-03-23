#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;

int board[101][101];
char event[10001];
//  아래, 오른쪽, 위, 왼쪽 
int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k, l;
	cin >> n >> k;


	for (int i = 0; i < k; ++i)
	{
		int r, c;
		cin >> r >> c;
		board[r][c] = -1; // 사과
	}

	cin >> l;

	for (int i = 0; i < l; ++i)
	{
		int x; char c;
		cin >> x >> c;
		event[x] = c;
	}

	deque<pair<int, int>> snake;
	int d = 1; // 오른쪽 방향
	snake.push_back({ 1,1 }); // (1,1)
	board[1][1] = 1; // 뱀

	int t = 0;


	while (1)
	{
		t++;

		int head_r = snake.back().first;
		int head_c = snake.back().second;

		int tail_r = snake.front().first;
		int tail_c = snake.front().second;

		int next_r = head_r + mx[d];
		int next_c = head_c + my[d];

		if (next_r > n || next_c > n || next_r < 1 || next_c < 1) // 벽 충돌
			break;
		if (board[next_r][next_c] == 1) // 자기 자신
			break;

		if (board[next_r][next_c] == -1) // 사과 -> 길이 추가 
		{
			board[next_r][next_c] = 1;
			snake.push_back({ next_r,next_c });
		}
		else if (board[next_r][next_c] == 0) // 빈칸 -> 꼬리 이동
		{
			board[tail_r][tail_c] = 0;
			board[next_r][next_c] = 1;
			snake.pop_front();
			snake.push_back({ next_r,next_c });
		}

		if (event[t] == 'L') // 왼쪽 회전
		{
			d++;
			d %= 4;
		}
		else if (event[t] == 'D') // 오른쪽 회전
		{
			d += 3;
			d %= 4;
		}

	}

	cout << t;

	return 0;
}