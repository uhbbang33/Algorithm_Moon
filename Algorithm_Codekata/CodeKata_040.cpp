//https://school.programmers.co.kr/learn/courses/30/lessons/68935
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(int n) {
    int answer = 0;

    vector<int> vec;
    int num = 0;

    while (n != 0) {
        num = n % 3;
        n /= 3;
        vec.push_back(num);
    }

    for (int i = 0; i < vec.size(); ++i)
        answer += vec[i] * pow(3, vec.size() - i - 1);

    return answer;
}