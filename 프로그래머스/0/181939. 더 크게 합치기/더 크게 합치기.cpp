#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string strA = to_string(a);
    string strB = to_string(b);
    
    answer = max(stoi(strA + strB), stoi(strB + strA));
    
    return answer;
}