//https://school.programmers.co.kr/learn/courses/30/lessons/12917
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = s;
    sort(answer.begin(), answer.end(), greater<>());
    return answer;
}