#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for(int& f : food)
        f /= 2;
    
    for(int i = 1; i < food.size(); ++i)
        for(int j = 0; j < food[i]; ++j)
            answer.push_back(i + '0');
    
    answer.push_back('0');
    
    for(int i = food.size()-1; i > 0; --i)
        for(int j = 0; j < food[i]; ++j)
            answer.push_back(i + '0');
    
    return answer;
}