#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    long long dd = pow(d,2);
    
    for(long long x = 0 ;x <= d; x+=k)
    {
        long long ky = sqrt(dd - pow(x,2)) ;
        long long y = ky / k;;
        answer += y+1;
    }
    
    return answer;
}