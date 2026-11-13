#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

using ll = long long;

struct Moments {
    ll cnt = 0;
    ll sum = 0;
};

// [l, r]에서 지정한 홀짝의 정수 개수와 합
Moments getMoments(ll l, ll r, int parity) {
    if (l > r) return {};

    if ((l & 1LL) != parity) ++l;
    if ((r & 1LL) != parity) --r;

    if (l > r) return {};

    ll cnt = (r - l) / 2 + 1;
    return {cnt, cnt * ((l + r) / 2)};
}

class CoverageTree {
    struct Node {
        ll cnt[2] = {};
        ll sum[2] = {};
        int cover = 0;
    };

    vector<ll> coords;
    vector<Node> tree;
    int size;

    void pull(int node, int l, int r) {
        Node& cur = tree[node];

        if (cur.cover > 0) {
            cur.cnt[0] = cur.cnt[1] = 0;
            cur.sum[0] = cur.sum[1] = 0;
            return;
        }

        if (l == r) {
            for (int p = 0; p < 2; ++p) {
                Moments v = getMoments(
                    coords[l], coords[l + 1] - 1, p
                );
                cur.cnt[p] = v.cnt;
                cur.sum[p] = v.sum;
            }
            return;
        }

        for (int p = 0; p < 2; ++p) {
            cur.cnt[p] =
                tree[node * 2].cnt[p]
                + tree[node * 2 + 1].cnt[p];

            cur.sum[p] =
                tree[node * 2].sum[p]
                + tree[node * 2 + 1].sum[p];
        }
    }

    void build(int node, int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
        }
        pull(node, l, r);
    }

    void update(int node, int l, int r,
                int ql, int qr, int delta) {
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            tree[node].cover += delta;
            pull(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, delta);
        update(node * 2 + 1, mid + 1, r, ql, qr, delta);
        pull(node, l, r);
    }

    Moments query(int node, int l, int r,
                  ll ql, ll qr, int parity) const {
        ll segL = coords[l];
        ll segR = coords[r + 1] - 1;

        if (qr < segL || segR < ql ||
            tree[node].cover > 0) {
            return {};
        }

        if (ql <= segL && segR <= qr) {
            return {
                tree[node].cnt[parity],
                tree[node].sum[parity]
            };
        }

        if (l == r) {
            return getMoments(
                max(ql, segL),
                min(qr, segR),
                parity
            );
        }

        int mid = (l + r) / 2;

        Moments a = query(
            node * 2, l, mid, ql, qr, parity
        );
        Moments b = query(
            node * 2 + 1, mid + 1, r,
            ql, qr, parity
        );

        return {a.cnt + b.cnt, a.sum + b.sum};
    }

public:
    explicit CoverageTree(vector<ll> positions)
        : coords(move(positions)) {
        sort(coords.begin(), coords.end());
        coords.erase(
            unique(coords.begin(), coords.end()),
            coords.end()
        );

        size = static_cast<int>(coords.size()) - 1;
        tree.resize(size * 4 + 4);
        build(1, 0, size - 1);
    }

    void add(ll l, ll r, int delta) {
        int ql = static_cast<int>(
            lower_bound(coords.begin(), coords.end(), l)
            - coords.begin()
        );

        int qr = static_cast<int>(
            lower_bound(coords.begin(), coords.end(), r + 1)
            - coords.begin()
        ) - 1;

        if (ql <= qr) {
            update(1, 0, size - 1, ql, qr, delta);
        }
    }

    Moments get(ll l, ll r, int parity) const {
        if (l > r) return {};
        return query(1, 0, size - 1, l, r, parity);
    }
};

struct Event {
    ll u, vl, vr;
    int delta;

    bool operator<(const Event& other) const {
        return u < other.u;
    }
};

// 고정된 제외 영역에서 u <= t인 유효 좌표 개수
ll countUpTo(
    ll t, ll n, ll m,
    ll vl, ll vr,
    const CoverageTree& tree
) {
    if (t < 0) return 0;

    ll result = 0;

    for (int p = 0; p < 2; ++p) {
        // v와 홀짝이 같은 t 이하의 마지막 정수
        ll tp = t - ((t - p) & 1LL);
        if (tp < 0) continue;

        ll low = max({vl, -m, -tp});
        ll high = min({vr, n, tp});
        if (low > high) continue;

        // 최소 상한이 변경되거나 |v|의 식이 바뀌는 위치
        vector<ll> cuts = {low, high + 1};

        ll candidates[4] = {
            0,
            n - m,
            2 * n - tp,
            tp - 2 * m
        };

        for (ll x : candidates) {
            if (low < x && x <= high) {
                cuts.push_back(x);
            }
        }

        sort(cuts.begin(), cuts.end());
        cuts.erase(
            unique(cuts.begin(), cuts.end()),
            cuts.end()
        );

        for (int i = 0;
             i + 1 < static_cast<int>(cuts.size());
             ++i) {

            ll l = cuts[i];
            ll r = cuts[i + 1] - 1;

            // 해당 홀짝의 첫 좌표
            ll v = l;
            if ((v & 1LL) != p) ++v;
            if (v > r) continue;

            Moments info = tree.get(v, r, p);
            if (info.cnt == 0) continue;

            // 교차점에서의 동점을 피하려고 구간의 마지막 좌표로 최소 상한 판정
            ll vLast = r;
            if ((vLast & 1LL) != p) --vLast;

            ll upper1 = tp;
            ll upper2 = 2 * n - vLast;
            ll upper3 = 2 * m + vLast;

            ll sumUpper;

            if (upper1 <= upper2 && upper1 <= upper3) {
                sumUpper = tp * info.cnt;
            } else if (upper2 <= upper3) {
                sumUpper =
                    2 * n * info.cnt - info.sum;
            } else {
                sumUpper =
                    2 * m * info.cnt + info.sum;
            }

            // 현재 구간에서는 v의 부호가 일정
            ll sumLower =
                (v >= 0) ? info.sum : -info.sum;

            result +=
                (sumUpper - sumLower) / 2 + info.cnt;
        }
    }

    return result;
}

long long solution(
    int n, int m,
    vector<vector<int>> tests
) {
    ll N = n;
    ll M = m;

    // 모든 도달 성공 테스트의 교집합
    ll ul = 0, ur = N + M;
    ll vl = -M, vr = N;

    for (const auto& test : tests) {
        if (test[3] != 1) continue;

        ll x = test[0], y = test[1], d = test[2];
        ll u = x + y;
        ll v = x - y;

        ul = max(ul, u - d);
        ur = min(ur, u + d);

        vl = max(vl, v - d);
        vr = min(vr, v + d);
    }

    if (ul > ur || vl > vr) return 0;

    // 도달 실패 테스트는 제외 직사각형으로 변환
    vector<Event> events;
    vector<ll> coords = {vl, vr + 1};

    events.reserve(tests.size() * 2);
    coords.reserve(tests.size() * 2 + 2);

    for (const auto& test : tests) {
        if (test[3] != 0) continue;

        ll x = test[0], y = test[1], d = test[2];
        ll u = x + y;
        ll v = x - y;

        ll a = max(ul, u - d);
        ll b = min(ur, u + d);
        ll c = max(vl, v - d);
        ll e = min(vr, v + d);

        if (a > b || c > e) continue;

        events.push_back({a, c, e, 1});
        events.push_back({b + 1, c, e, -1});

        coords.push_back(c);
        coords.push_back(e + 1);
    }

    sort(events.begin(), events.end());

    CoverageTree tree(move(coords));

    ll answer = 0;
    ll current = ul;
    int i = 0;
    int eventCount = static_cast<int>(events.size());

    while (i < eventCount && events[i].u <= ur) {
        ll nextU = events[i].u;

        // 제외 영역이 동일한 u 구간을 한 번에 계산
        if (current < nextU) {
            answer +=
                countUpTo(
                    nextU - 1, N, M, vl, vr, tree
                )
                - countUpTo(
                    current - 1, N, M, vl, vr, tree
                );
        }

        // 같은 위치의 이벤트를 모두 반영
        while (i < eventCount &&
               events[i].u == nextU) {
            tree.add(
                events[i].vl,
                events[i].vr,
                events[i].delta
            );
            ++i;
        }

        current = nextU;
    }

    // 마지막 이벤트 이후 남은 구간 계산
    if (current <= ur) {
        answer +=
            countUpTo(ur, N, M, vl, vr, tree)
            - countUpTo(
                current - 1, N, M, vl, vr, tree
            );
    }

    return answer;
}