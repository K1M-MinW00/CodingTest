
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

// HH:MM -> 분
int toMinutes(const string& time) {
    return stoi(time.substr(0, 2)) * 60
         + stoi(time.substr(3, 2));
}

// 분 -> HH:MM
string toTimeString(int minutes) {
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "%02d:%02d",
             minutes / 60, minutes % 60);
    return string(buffer);
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> arrivals;
    arrivals.reserve(timetable.size());

    for (const string& time : timetable) {
        arrivals.push_back(toMinutes(time));
    }

    sort(arrivals.begin(), arrivals.end());

    int crewIndex = 0;
    int lastBoardedTime = -1;
    int boarded = 0;
    int shuttleTime = 540;

    // 셔틀 운행 및 크루 탑승 시뮬레이션
    for (int i = 0; i < n; ++i) {
        shuttleTime = 540 + i * t;
        boarded = 0;

        while (boarded < m &&
               crewIndex < static_cast<int>(arrivals.size()) &&
               arrivals[crewIndex] <= shuttleTime) {
            lastBoardedTime = arrivals[crewIndex++];
            ++boarded;
        }
    }

    // 마지막 셔틀에 빈자리가 있다면 출발 시각에 도착
    // 만석이라면 마지막 탑승 크루보다 1분 먼저 도착
    int answer = (boarded < m)
               ? shuttleTime
               : lastBoardedTime - 1;

    return toTimeString(answer);
}