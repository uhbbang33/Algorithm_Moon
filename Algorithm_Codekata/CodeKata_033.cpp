//https://school.programmers.co.kr/learn/courses/30/lessons/77884
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int num = 0;
    for (int i = left; i <= right; ++i) {
        num = 0;
        for (int j = 1; j <= i; ++j)
            if (i % j == 0)
                ++num;
        if (num % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}