#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    if (n > m) swap(n, m);
    int num1 = n, num2 = m;

    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    answer.push_back(num1);
    answer.push_back(n* m / num1);
    
    return answer;
}