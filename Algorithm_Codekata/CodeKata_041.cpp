//https://school.programmers.co.kr/learn/courses/30/lessons/12930
#include <string>
#include <vector>

using namespace std;

// 1. ������ �������� ������
// 2. Ȧ�� ¦�� ����
// 3. �빮�� �ҹ��� ����

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
        if (cnt % 2 == 1) {   // Ȧ��
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