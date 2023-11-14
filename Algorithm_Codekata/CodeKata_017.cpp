#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    string s = to_string(n);
    vector<int> answer;
    for (int i = 1; i <= s.length(); ++i)
        answer.push_back(s[s.length() - i] - '0');
    return answer;
}