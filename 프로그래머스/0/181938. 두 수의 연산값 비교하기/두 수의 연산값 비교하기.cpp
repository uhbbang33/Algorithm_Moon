#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    int ab2 = 2 * a * b;
    answer = max(ab2, stoi(to_string(a) + to_string(b)));
    
    return answer;
}