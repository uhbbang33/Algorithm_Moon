//https://school.programmers.co.kr/learn/courses/30/lessons/12935
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1)
    {
        answer.push_back(-1);
        return answer;
    }

    int min = INT_MAX;
    int indexNum = -1;
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] < min)
        {
            min = arr[i];
            indexNum = i;
        }
    for (int i = 0; i < arr.size(); ++i)
        if (i != indexNum)
            answer.push_back(arr[i]);

    return answer;
}