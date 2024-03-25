#include <iostream>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
	vector<double> answer;

	vector<int> v(1, k);
	while (k != 1)
	{
		if (k % 2 == 0)
			k /= 2;

		else
			k = 3 * k + 1;

		v.push_back(k);
	}

	int n = v.size() - 1;

	vector<double> vsum(n, 0);

	for (int i = 0; i < n; ++i)
		vsum[i] += (v[i] + v[i + 1]) / 2.0;


	for (int i = 0; i < ranges.size(); ++i)
	{
		int a = ranges[i][0];
		int b = n + ranges[i][1];


		if (a > b)
			answer.push_back(-1);

		else
		{
			double sum = 0;

			for (int j = a; j < b; ++j)
				sum += vsum[j];

			answer.push_back(sum);
		}

	}
	return answer;
}