//https://school.programmers.co.kr/learn/courses/30/lessons/12943

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    if (num == 1)
        return 0;

    for (int i = 1; i < 500; ++i) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;

        if (n == 1) {
            answer = i;
            break;
        }
    }
    if (n != 1)
        answer = -1;

    return answer;
}