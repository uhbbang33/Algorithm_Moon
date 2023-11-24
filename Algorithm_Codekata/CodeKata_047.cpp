#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    sort(answer.begin(), answer.end(), [n](string a, string b) {
        if (a[n] == b[n])
            if (a > b) return false;
            else return true;
        if (a[n] > b[n]) return false;
        else return true;
        });

    return answer;
}
