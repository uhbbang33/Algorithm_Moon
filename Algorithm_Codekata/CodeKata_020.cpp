#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    vector<int> vec;
    string s = to_string(n);
    
    for (char c : s) {
        vec.push_back(c - '0');
    }
    sort(vec.begin(), vec.end(), less<>());

    for (int i = 0; i < vec.size(); ++i)
        answer += vec[i] * pow(10, i);

    return answer;
}