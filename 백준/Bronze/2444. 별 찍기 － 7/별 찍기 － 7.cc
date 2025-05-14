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

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		for (int j = n - i; j > 0; j--) 
			cout << " ";

		for (int j = 2 * i - 1; j > 0; j--) 
			cout << "*";
		
		cout << '\n';
	}

	for (int i = 1; i < n; i++) {

		for (int j = 0; j < i; j++)
			cout << " ";

		for (int j = 2 * (n - i) - 1; j > 0; j--)
			cout << "*";

		cout << '\n';
	}
	
	return 0;
}