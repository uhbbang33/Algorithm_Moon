//https://school.programmers.co.kr/learn/courses/30/lessons/12903
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int num = s.size() / 2;
    if (s.size() % 2 == 0)
        answer += s[num - 1];
    answer += s[num];

    return answer;
}