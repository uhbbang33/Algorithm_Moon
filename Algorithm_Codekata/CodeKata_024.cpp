//https://school.programmers.co.kr/learn/courses/30/lessons/12919
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int resultNum = 0;
    for (int i = 0; i < seoul.size(); ++i)
        if (seoul[i] == "Kim")
            resultNum = i;
    string answer = "�輭���� " + to_string(resultNum) + "�� �ִ�";

    return answer;
}