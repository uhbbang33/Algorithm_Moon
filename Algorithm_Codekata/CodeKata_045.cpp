#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    string answer = s;

    for (char& c : answer) {
        if (isupper(c)) {
            c += n;
            if (c > 'Z') { c = c - 'Z' + 'A' - 1; }
        }
        else if (islower(c)) {
            c += n - 26;
            if (c < 'a') { c += 26; }
        }
    }
    return answer;
}