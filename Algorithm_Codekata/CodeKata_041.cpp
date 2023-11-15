//https://school.programmers.co.kr/learn/courses/30/lessons/12930
#include <string>
#include <vector>

using namespace std;

// 1. 공백을 기준으로 나누기
// 2. 홀수 짝수 구분
// 3. 대문자 소문자 구분

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ')
        {
            cnt = 0;
            answer += ' ';
            continue;
        }
        ++cnt;
        if (cnt % 2 == 1) {   // 홀수
            if (islower(s[i]))
                s[i] = toupper(s[i]);
        }
        else
            if (isupper(s[i]))
                s[i] = tolower(s[i]);

        answer += s[i];
    }

    return answer;
}