#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> A(n);

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		A[i] = { tmp,i }; // 값, 인덱스
	}

	sort(A.begin(), A.end()); // 값 기준 오름차순 정렬 (값이 같다면, 인덱스 기준 오름차순)

	vector<int> B(n, 0);

	for (int i = 0; i < n; ++i)
		B[A[i].second] = i;


	for (int i = 0; i < n; ++i)
		cout << B[i] << ' ';

	return 0;
}