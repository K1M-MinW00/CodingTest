
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MOD = 10000019;

// 1. 각 열의 1 개수 계산
vector<int> calculateColumnCounts(const vector<vector<int>>& a) {
    int rows = a.size();
    int cols = a[0].size();

    vector<int> counts(cols, 0);

    for (const auto& row : a) {
        for (int j = 0; j < cols; ++j) {
            counts[j] += row[j];
        }
    }

    return counts;
}

// 2. 조합 테이블 생성
vector<vector<int>> buildCombinations(int n) {
    vector<vector<int>> comb(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i) {
        comb[i][0] = comb[i][i] = 1;

        for (int j = 1; j < i; ++j) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    return comb;
}

// 3. 모든 행의 1 개수가 짝수인 배열의 경우의 수 계산
int countEvenRowMatrices(
    int n,
    const vector<int>& counts,
    const vector<vector<int>>& comb
) {
    vector<int> dp(n + 1, 0);
    vector<int> nextDp(n + 1, 0);

    dp[n] = 1;

    for (int k : counts) {
        fill(nextDp.begin(), nextDp.end(), 0);

        for (int even = 0; even <= n; ++even) {
            if (dp[even] == 0) continue;

            int odd = n - even;

            int low = max(0, k - odd);
            int high = min(even, k);

            for (int chosenEven = low; chosenEven <= high; ++chosenEven) {
                int nextEven = even + k - 2 * chosenEven;

                long long ways =
                    1LL * comb[even][chosenEven]
                    * comb[odd][k - chosenEven] % MOD;

                nextDp[nextEven] =
                    (nextDp[nextEven] + dp[even] * ways) % MOD;
            }
        }

        dp.swap(nextDp);
    }

    return dp[n];
}

// 4. 전체 알고리즘 실행
int solution(vector<vector<int>> a) {
    int n = a.size();

    vector<int> counts = calculateColumnCounts(a);

    int total = 0;
    for (int k : counts) {
        total += k;
    }

    if (total % 2 != 0) return 0;

    vector<vector<int>> comb = buildCombinations(n);

    return countEvenRowMatrices(n, counts, comb);
}
