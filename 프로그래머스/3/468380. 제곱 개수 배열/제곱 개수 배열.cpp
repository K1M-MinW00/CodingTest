
#include <vector>
#include <algorithm>
using namespace std;

// brr의 처음 count개 원소의 합
long long getPrefixSum(
    const vector<int>& arr,
    const vector<long long>& prefixLen,
    const vector<long long>& prefixSum,
    long long count
) {
    if (count == prefixLen.back()) {
        return prefixSum.back();
    }

    int idx = static_cast<int>(
        upper_bound(prefixLen.begin(), prefixLen.end(), count)
        - prefixLen.begin() - 1
    );

    long long remaining = count - prefixLen[idx];

    return prefixSum[idx] + remaining * arr[idx];
}

// 길이가 windowLen이고 합이 target인 부분 배열 개수
long long countMatchingWindows(
    const vector<int>& arr,
    const vector<long long>& prefixLen,
    long long windowLen,
    long long target,
    long long initialSum
) {
    long long totalLen = prefixLen.back();
    long long lastStart = totalLen - windowLen;

    // 가능한 부분 배열이 전체 brr 하나뿐인 경우
    if (lastStart == 0) {
        return initialSum == target ? 1LL : 0LL;
    }

    int leftIdx = 0;
    int rightIdx = static_cast<int>(
        upper_bound(prefixLen.begin(), prefixLen.end(), windowLen)
        - prefixLen.begin() - 1
    );

    long long start = 0;
    long long currentSum = initialSum;
    long long answer = 0;

    while (start < lastStart) {
        // 양쪽 포인터가 다음 반복 구간에 진입하는 위치
        long long nextLeft = prefixLen[leftIdx + 1];
        long long nextRight =
            prefixLen[rightIdx + 1] - windowLen;

        long long nextStart =
            min(lastStart, min(nextLeft, nextRight));

        long long count = nextStart - start;

        // 윈도우를 한 칸 이동할 때 합의 변화량
        long long diff =
            static_cast<long long>(arr[rightIdx]) - arr[leftIdx];

        // 등차수열에서 target과 일치하는 위치 계산
        if (diff == 0) {
            if (currentSum == target) {
                answer += count;
            }
        } else {
            long long delta = target - currentSum;

            if (delta % diff == 0) {
                long long offset = delta / diff;

                if (0 <= offset && offset < count) {
                    ++answer;
                }
            }
        }

        // 다음 구간의 시작 위치에 해당하는 합으로 갱신
        currentSum += diff * count;
        start = nextStart;

        if (start == nextLeft) {
            ++leftIdx;
        }
        if (start == nextRight) {
            ++rightIdx;
        }
    }

    // 마지막 시작 위치는 별도로 검사
    if (currentSum == target) {
        ++answer;
    }

    return answer;
}

vector<long long> solution(vector<int> arr, long long l, long long r) {
    int n = static_cast<int>(arr.size());

    vector<long long> prefixLen(n + 1, 0);
    vector<long long> prefixSum(n + 1, 0);

    // 1. 압축된 구간의 길이 및 합 누적
    for (int i = 0; i < n; ++i) {
        long long value = arr[i];

        prefixLen[i + 1] = prefixLen[i] + value;
        prefixSum[i + 1] = prefixSum[i] + value * value;
    }

    // 2. 주어진 구간의 길이와 합 K 계산
    long long windowLen = r - l + 1;

    long long K =
        getPrefixSum(arr, prefixLen, prefixSum, r)
        - getPrefixSum(arr, prefixLen, prefixSum, l - 1);

    // 3. 첫 윈도우의 합 계산
    long long initialSum =
        getPrefixSum(arr, prefixLen, prefixSum, windowLen);

    // 4. 합이 K인 길이 windowLen의 부분 배열 개수
    long long C = countMatchingWindows(
        arr, prefixLen, windowLen, K, initialSum
    );

    return {K, C};
}
