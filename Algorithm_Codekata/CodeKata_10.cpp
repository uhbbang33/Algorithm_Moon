#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    int sum = 0;
    for (int num : numbers)
        sum += num;

    double answer = (double)sum / numbers.size();

    return answer;
}