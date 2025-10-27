#include<iostream>
#include<algorithm>

using namespace std;


int main()
{
	long long N;
	cin >> N;
	
	int arr[11];
	int i = 0;
	while (1) {
		if (N == 0) {
			break;
		}
		arr[i] = N % 10;
		N /= 10;
		i++;
	}

	sort(arr, arr + i, greater<>());
	for (int j = 0; j < i; j++)
		cout << arr[j];

	return 0;
}