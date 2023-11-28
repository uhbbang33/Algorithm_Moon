#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    bool isNumber[201] = {};

    for (int i = 0; i < numbers.size() - 1; ++i)
        for (int j = i + 1; j < numbers.size(); ++j)
            isNumber[numbers[i] + numbers[j]] = true;

    for (int i = 0; i < 201; ++i)
        if (isNumber[i])
            answer.push_back(i);

    return answer;
}