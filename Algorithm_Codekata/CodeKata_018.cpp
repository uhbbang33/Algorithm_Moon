#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i = 1; i < s.length(); ++i)
        answer += (s[i] - '0') * pow(10, s.length() - i - 1);

    if (s[0] == '+')
        return answer;
    else if(s[0] == '-')
        answer *= -1;
    else
        answer += (s[0] -'0') * pow(10, s.length() -1);

    return answer;
}
