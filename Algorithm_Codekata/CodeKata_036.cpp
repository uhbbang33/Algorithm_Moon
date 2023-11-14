//https://school.programmers.co.kr/learn/courses/30/lessons/12918
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = false;

    if (4 == s.length() || s.length() == 6)
        for (char c : s) {
            if ('0' <= c && c <= '9')
                answer = true;
            else {
                answer = false;
                break;
            }
        }
    else
        answer = false;

    return answer;
}