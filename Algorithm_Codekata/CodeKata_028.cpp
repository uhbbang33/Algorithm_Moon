//https://school.programmers.co.kr/learn/courses/30/lessons/86051
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool isContain = false;
    for (int i = 0; i < 10; ++i) {
        isContain = false;
        for (int j = 0; j < numbers.size(); ++j) {
            if (i == numbers[j])
            {
                isContain = true;
                break;
            }
        }
        if (!isContain)
            answer += i;
    }

    return answer;
}