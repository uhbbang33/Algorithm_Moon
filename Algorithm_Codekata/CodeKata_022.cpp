#include <string>
#include <vector>
using namespace std;

//https://school.programmers.co.kr/learn/courses/30/lessons/12912
long long solution(int a, int b) {
    long long answer = 0;
    if (a > b)
        swap(a, b);

    for (int i = 0; i <= b - a; ++i)
        answer += a + i;

    return answer;
}