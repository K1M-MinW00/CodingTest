
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> a) {
    int n = static_cast<int>(a.size());
    int leftMin = INT_MAX;
    int rightMin = INT_MAX;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        // 왼쪽에서 새로운 최솟값 발견
        if (a[i] < leftMin) {
            leftMin = a[i];
            ++count;
        }

        // 오른쪽에서 새로운 최솟값 발견
        if (a[n - 1 - i] < rightMin) {
            rightMin = a[n - 1 - i];
            ++count;
        }
    }

    // 전체 최솟값은 양쪽에서 중복 집계됨
    return count - 1;
}
