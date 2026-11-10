
#include <vector>
#include <algorithm>
using namespace std;

// 주어진 시간 내에 필요한 금과 은을 운반할 수 있는지 판별
bool canTransport(long long time, int a, int b,
                  const vector<int>& g, const vector<int>& s,
                  const vector<int>& w, const vector<int>& t) {
    long long totalGold = 0;
    long long totalSilver = 0;
    long long totalWeight = 0;

    int n = g.size();

    for (int i = 0; i < n; ++i) {
        long long roundTrip = 2LL * t[i];

        // 왕복 횟수 + 마지막 편도 운반 여부
        long long trips = time / roundTrip;
        if (time % roundTrip >= t[i]) {
            ++trips;
        }

        long long capacity = trips * w[i];

        totalGold += min((long long)g[i], capacity);
        totalSilver += min((long long)s[i], capacity);
        totalWeight += min((long long)g[i] + s[i], capacity);

        // 세 조건을 만족하면 나머지 도시를 확인할 필요 없음
        if (totalGold >= a && totalSilver >= b &&
            totalWeight >= (long long)a + b) {
            return true;
        }
    }

    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s,
                   vector<int> w, vector<int> t) {
    long long left = 0;
    long long right = 400000000000000LL;

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canTransport(mid, a, b, g, s, w, t)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
