
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

constexpr int MOD = 1000000007;

int addMod(int a, int b) {
    int sum = a + b;
    return sum >= MOD ? sum - MOD : sum;
}

int subMod(int a, int b) {
    int diff = a - b;
    return diff < 0 ? diff + MOD : diff;
}

struct Point {
    ll x, y, k, t;
    int sourceGroup = -1;
    int targetGroup = -1;
    int forward = 0;
    int backward = 0;
};

struct Group {
    // 시작점에서의 경로 수 계산용
    vector<ll> xs;
    vector<int> prefix;

    // 도착점까지의 경로 수 계산용
    vector<ll> thresholds;
    vector<int> bit;

    void prepare() {
        if (thresholds.empty()) return;

        sort(thresholds.begin(), thresholds.end());
        thresholds.erase(
            unique(thresholds.begin(), thresholds.end()),
            thresholds.end()
        );

        bit.assign(thresholds.size() + 1, 0);
    }

    // x 이하에 있는 점들의 forward 합
    int prefixAt(ll x) const {
        int count = static_cast<int>(
            upper_bound(xs.begin(), xs.end(), x) - xs.begin()
        );

        return count == 0 ? 0 : prefix[count - 1];
    }

    void addForward(ll x, int value) {
        int sum = value;

        if (!prefix.empty()) {
            sum = addMod(sum, prefix.back());
        }

        xs.push_back(x);
        prefix.push_back(sum);
    }

    // Fenwick Tree에 backward 값 추가
    void addBackward(ll threshold, int value) {
        if (value == 0 || thresholds.empty()) return;

        int idx = static_cast<int>(
            lower_bound(
                thresholds.begin(), thresholds.end(), threshold
            ) - thresholds.begin()
        ) + 1;

        int size = static_cast<int>(bit.size());

        for (; idx < size; idx += idx & -idx) {
            bit[idx] = addMod(bit[idx], value);
        }
    }

    // threshold < x인 점들의 backward 합
    int backwardAt(ll x) const {
        if (thresholds.empty()) return 0;

        int idx = static_cast<int>(
            lower_bound(
                thresholds.begin(), thresholds.end(), x
            ) - thresholds.begin()
        );

        int result = 0;

        for (; idx > 0; idx -= idx & -idx) {
            result = addMod(result, bit[idx]);
        }

        return result;
    }
};

// 압축된 t 좌표에서 그룹 찾기
int findGroup(const vector<ll>& keys, ll t) {
    auto it = lower_bound(keys.begin(), keys.end(), t);

    if (it == keys.end() || *it != t) {
        return -1;
    }

    return static_cast<int>(it - keys.begin());
}

// 특정 점까지 도달하는 경로 수 계산
int getForward(
    const vector<Group>& groups,
    int groupId,
    ll x,
    ll k
) {
    // 가로와 세로가 모두 양수여야 함
    if (groupId == -1 || k < 2) return 0;

    const Group& group = groups[groupId];

    return subMod(
        group.prefixAt(x - 1),
        group.prefixAt(x - k)
    );
}

vector<int> solution(
    int n,
    vector<vector<int>> point,
    vector<vector<int>> query
) {
    // 1. 점 정렬 및 좌표 변환
    vector<Point> points;
    points.reserve(n);

    vector<ll> keys;
    keys.reserve(2 * n);

    for (const auto& p : point) {
        ll x = p[0];
        ll y = p[1];
        ll k = p[2];
        ll t = x - y;

        points.push_back({x, y, k, t});

        keys.push_back(t);
        keys.push_back(t - k);
    }

    sort(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            return a.x < b.x;
        }
    );

    sort(keys.begin(), keys.end());
    keys.erase(
        unique(keys.begin(), keys.end()),
        keys.end()
    );

    vector<Group> groups(keys.size());

    // 2. 그룹 인덱스 및 Fenwick 좌표 준비
    for (Point& p : points) {
        p.sourceGroup = findGroup(keys, p.t);
        p.targetGroup = findGroup(keys, p.t - p.k);

        if (p.k >= 2) {
            groups[p.targetGroup].thresholds.push_back(
                p.x - p.k
            );
        }
    }

    for (Group& group : groups) {
        group.prepare();
    }

    // 3. x 오름차순: 시작점에서 각 점까지의 경로 수
    for (int i = 0; i < n; ++i) {
        Point& p = points[i];

        if (i == 0) {
            // 최초의 가장 왼쪽 점이 S
            p.forward = 1;
        } else {
            p.forward = getForward(
                groups, p.targetGroup, p.x, p.k
            );
        }

        groups[p.sourceGroup].addForward(
            p.x, p.forward
        );
    }

    // 가장 오른쪽 점이 E
    int total = points[n - 1].forward;

    int qCount = static_cast<int>(query.size());
    vector<int> answer(qCount + 1, 0);
    answer[0] = total;

    // 4. 추가 질의의 forward를 미리 계산
    vector<int> addQueries;
    addQueries.reserve(qCount);

    for (int i = 0; i < qCount; ++i) {
        if (query[i][0] != 0) continue;

        addQueries.push_back(i);

        ll x = query[i][1];
        ll y = query[i][2];
        ll k = query[i][3];

        int groupId = findGroup(keys, x - y - k);

        // 임시로 추가된 점의 forward 저장
        answer[i + 1] = getForward(
            groups, groupId, x, k
        );
    }

    // 5. 추가 질의를 x 내림차순으로 처리
    sort(addQueries.begin(), addQueries.end(),
        [&](int a, int b) {
            return query[a][1] > query[b][1];
        }
    );

    int idx = n - 1;

    // 기존 점 하나의 backward 계산 및 등록
    auto processPoint = [&](int i) {
        Point& p = points[i];

        if (i == n - 1) {
            p.backward = 1;
        } else {
            p.backward =
                groups[p.sourceGroup].backwardAt(p.x);
        }

        if (p.k >= 2) {
            groups[p.targetGroup].addBackward(
                p.x - p.k, p.backward
            );
        }
    };

    for (int qi : addQueries) {
        ll x = query[qi][1];
        ll y = query[qi][2];

        // 새로운 점보다 오른쪽에 있는 기존 점만 등록
        while (idx >= 0 && points[idx].x > x) {
            processPoint(idx);
            --idx;
        }

        int groupId = findGroup(keys, x - y);

        int backward = 0;

        if (groupId != -1) {
            backward = groups[groupId].backwardAt(x);
        }

        int forward = answer[qi + 1];

        int addedPaths = static_cast<int>(
            1LL * forward * backward % MOD
        );

        answer[qi + 1] = addMod(total, addedPaths);
    }

    // 6. 나머지 기존 점의 backward 계산
    while (idx >= 0) {
        processPoint(idx);
        --idx;
    }

    // 7. 삭제 질의 처리
    for (int i = 0; i < qCount; ++i) {
        if (query[i][0] != 1) continue;

        ll x = query[i][1];

        auto it = lower_bound(
            points.begin(), points.end(), x,
            [](const Point& p, ll value) {
                return p.x < value;
            }
        );

        // 삭제 대상은 반드시 기존 점에 존재
        int removedPaths = static_cast<int>(
            1LL * it->forward * it->backward % MOD
        );

        answer[i + 1] = subMod(total, removedPaths);
    }

    return answer;
}
