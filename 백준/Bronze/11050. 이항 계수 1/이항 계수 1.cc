#include<iostream>
#include<algorithm>

using namespace std;

int binom(int n, int k) {
	if (k == n || k == 0) {
		return 1;
	}
	else {
		return binom(n - 1, k) + binom(n - 1, k - 1);
	}
}
int main()
{
	int n,k;
	cin >> n >> k;

	
	cout << binom(n,k);
	return 0;
}