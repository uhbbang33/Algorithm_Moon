#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string s) {
    int answer = 0;

    string result = "";
    for (int i = 0; i < s.length(); ++i) {
        if (!isalpha(s[i]))
        {
            result += s[i];
            continue;
        }

        switch (s[i])
        {
        case 'z':
            result += "0";
            i += 3;
            break;
        case 'o':
            result += "1";
            i += 2;
            break;
        case 't':
            if (s[i + 1] == 'w') {
                result += "2";
                i += 2;
            }
            else {
                result += "3";
                i += 4;
            }
            break;
        case 'f':
            if (s[i + 1] == 'o')
                result += "4";
            else
                result += "5";
            i += 3;
            break;
        case 's':
            if (s[i + 1] == 'i') {
                result += "6";
                i += 2;
            }
            else {
                result += "7";
                i += 4;
            }
            break;
        case 'e':
            result += "8";
            i += 4;
            break;
        case 'n':
            result += "9";
            i += 3;
            break;
        }
    }

    int cnt = 0;
    for (int i = result.length() - 1; i >= 0; --i) {
        answer += (result[i] - '0') * pow(10, cnt);
        ++cnt;
    }

    return answer;
}
