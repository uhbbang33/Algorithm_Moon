#include <string>
#include <math.h>
#include <iostream>
using namespace std;

int solution(string t, string p) {
    int answer = 0;

    string s = "";

    long long pInt = 0;
    for (int i = 0; i < p.length(); ++i)
        pInt += (p[i] - '0') * pow(10, p.length() - i - 1);

    for (int i = 0; i <= t.length() - p.length(); ++i) {
        for (int j = 0; j < p.length(); ++j)
            s += t[i + j];
        
        long long a = 0;
        for (int j = 0; j < s.length(); ++j)
            a += (s[j] - '0') * pow(10, s.length() - j - 1);

        if (a <= pInt)
            ++answer;
        s = "";
    }
    return answer;
}