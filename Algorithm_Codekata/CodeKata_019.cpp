#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;

    if (n == 1)
        return pow(n + 1, 2);

    answer = sqrt(n);
    if (n / answer == answer && n % answer == 0)
        answer = pow(answer + 1, 2);
    else
        answer = -1;

    return answer;
}