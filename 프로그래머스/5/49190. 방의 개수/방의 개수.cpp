
#include <vector>
#include <unordered_map>
#include <cstdint>
using namespace std;

// 좌표 (x, y)를 고유한 64비트 정수로 변환
uint64_t encodePosition(int x, int y) {
    return (static_cast<uint64_t>(static_cast<uint32_t>(x)) << 32)
         | static_cast<uint32_t>(y);
}

int solution(vector<int> arrows) {
    // 0: 위, 1: 오른쪽 위, 2: 오른쪽, ... 7: 왼쪽 위
    const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    // 각 정점에서 방문한 방향을 8비트로 관리
    unordered_map<uint64_t, uint8_t> visited;
    visited.reserve(arrows.size() * 2 + 1);

    int x = 0, y = 0;
    int roomCount = 0;

    visited.emplace(encodePosition(x, y), 0);

    for (int dir : arrows) {
        // 대각선 교차 처리를 위해 각 이동을 2번 수행
        for (int step = 0; step < 2; ++step) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            uint64_t current = encodePosition(x, y);
            uint64_t next = encodePosition(nx, ny);

            auto currentIt = visited.find(current);

            uint8_t directionBit = static_cast<uint8_t>(1u << dir);
            uint8_t reverseBit =
                static_cast<uint8_t>(1u << ((dir + 4) % 8));

            bool edgeVisited =
                (currentIt->second & directionBit) != 0;

            bool vertexVisited = visited.contains(next);

            // 방문한 정점으로 새로운 간선을 연결하면 방 생성
            if (vertexVisited && !edgeVisited) {
                ++roomCount;
            }

            // 양방향 간선 방문 처리
            currentIt->second |= directionBit;
            visited[next] |= reverseBit;

            x = nx;
            y = ny;
        }
    }

    return roomCount;
}
