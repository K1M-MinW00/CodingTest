
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int n = num.size();

    // 1. 루트 노드 찾기
    vector<bool> hasParent(n, false);

    for (int i = 0; i < n; ++i) {
        for (int child : links[i]) {
            if (child != -1) {
                hasParent[child] = true;
            }
        }
    }

    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (!hasParent[i]) {
            root = i;
            break;
        }
    }

    // 2. 반복형 DFS로 후위 순회 순서 생성
    vector<int> order;
    order.reserve(n);

    vector<int> st = {root};

    while (!st.empty()) {
        int node = st.back();
        st.pop_back();

        order.push_back(node);

        for (int child : links[node]) {
            if (child != -1) {
                st.push_back(child);
            }
        }
    }

    reverse(order.begin(), order.end());

    // 3. 그룹 최대 인원이 limit 이하인지 판별
    vector<long long> groupSum(n, 0);

    auto canDivide = [&](long long limit) -> bool {
        int cutCount = 0;

        for (int node : order) {
            int left = links[node][0];
            int right = links[node][1];

            long long leftSum = (left == -1) ? 0 : groupSum[left];
            long long rightSum = (right == -1) ? 0 : groupSum[right];
            long long current = num[node];

            if (current + leftSum + rightSum <= limit) {
                // 두 자식 그룹 모두 연결
                groupSum[node] = current + leftSum + rightSum;
            }
            else if (current + min(leftSum, rightSum) <= limit) {
                // 큰 자식 그룹과의 연결을 제거
                ++cutCount;
                groupSum[node] = current + min(leftSum, rightSum);
            }
            else {
                // 두 자식 그룹과의 연결을 모두 제거
                cutCount += 2;
                groupSum[node] = current;
            }

            if (cutCount >= k) {
                return false;
            }
        }

        return true;
    };

    // 4. 최대 그룹 인원의 최솟값 이진 탐색
    long long low = *max_element(num.begin(), num.end());
    long long high = accumulate(num.begin(), num.end(), 0LL);

    while (low < high) {
        long long mid = low + (high - low) / 2;

        if (canDivide(mid)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return static_cast<int>(low);
}
