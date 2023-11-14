#include <string>
#include <vector>

// https://school.programmers.co.kr/learn/courses/30/lessons/12947
using namespace std;

bool solution(int x) {
    string s = to_string(x);
    int sum = 0;
    for (char c : s)
        sum += c - '0';

    bool answer = true;
    if (x % sum != 0)
        answer = false;

    return answer;
}