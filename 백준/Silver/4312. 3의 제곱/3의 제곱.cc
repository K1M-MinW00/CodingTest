#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include<bitset>
#include <unordered_map>
using namespace std;

string multiplyByThree(const string& num) {
	string result;
	int carry = 0;

	for (int i = num.size() - 1; i >= 0; --i) {
		int digit = (num[i] - '0') * 3 + carry;
		result.push_back((digit % 10) + '0');
		carry = digit / 10;
	}
	if (carry > 0) result.push_back(carry + '0');
	reverse(result.begin(), result.end());
	return result;
}

string addBigIntegers(const string& a, const string& b) {
	string result;
	int carry = 0;

	int n = max(a.size(), b.size());
	// 뒤에서부터 자리수 맞추기 위해 0으로 채움
	string A = string(n - a.size(), '0') + a;
	string B = string(n - b.size(), '0') + b;

	for (int i = n - 1; i >= 0; --i) {
		int sum = (A[i] - '0') + (B[i] - '0') + carry;
		result.push_back((sum % 10) + '0');
		carry = sum / 10;
	}
	if (carry) result.push_back(carry + '0');
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	while (1)
	{
		unsigned long long n;
		cin >> n;


		if (n == 0)
			break;

		n -= 1;
		string sum = "0";
		string power = "1"; // 3^0

		cout << "{ ";

		while (n > 0)
		{
			if (n & 1)
			{
				sum = addBigIntegers(sum, power);

				cout << power;

				if (n >> 1 > 0)
					cout << ", ";
				else
					cout << ' ';
			}
			n >>= 1;
			power = multiplyByThree(power);

		}

		cout << "}" << '\n';
	}


	return 0;
}