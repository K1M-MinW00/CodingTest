#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);

	for (int i = 0; i < n; ++i)
		cin >> A[i];

	for (int i = 0; i < n; ++i)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int answer = 0;
	for (int i = 0; i < n; ++i)
		answer += (A[i] * B[n-1-i]);

	cout << answer;

	return 0;
}