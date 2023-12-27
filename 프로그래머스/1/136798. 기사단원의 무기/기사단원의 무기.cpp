#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> answers(number + 1);
    
    for(int i = 1; i <= number; ++i) {
        int cnt = 0;
        for(int j = 1; j * j <= i; ++j)
            if(i % j == 0)
                cnt += i / j == j ? 1 : 2;
        answers[i] += cnt > limit ? power : cnt;
    }
    
    for(int a : answers)
        answer += a;
    
    return answer;
}