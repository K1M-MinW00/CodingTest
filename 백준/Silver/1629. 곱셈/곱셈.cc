#include <iostream>
using namespace std;

long long a, b, c;

long long recursive(long long k)
{
	if (k == 1)
		return a % c;

	long long tmp = recursive(k / 2) % c;

	if (k % 2 == 0) // a^(b/2) * a^(b/2) = a^b
		return (tmp * tmp) % c;
	
	else // a^(b/2) * a^(b/2) * a = a^b
		return (tmp * tmp) % c * (a % c) ;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	long long answer = recursive(b) % c;

	cout << answer;
	return 0;
}