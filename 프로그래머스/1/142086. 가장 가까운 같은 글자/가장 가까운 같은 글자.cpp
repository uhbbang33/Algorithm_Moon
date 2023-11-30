#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    map<char, int> m;

    for (int i = 0; i < s.length(); ++i)
    {
        if (m.find(s[i]) == m.end()) {
            m.insert({ s[i], i });
            answer.push_back(-1);
        }
        else {
            answer.push_back(i - m.find(s[i])->second);
            m.find(s[i])->second = i;
        }
    }
    return answer;
}