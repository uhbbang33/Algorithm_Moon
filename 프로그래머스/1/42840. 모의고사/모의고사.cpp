#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> result;
    
    int correct[3] = {};
    int supozaThreeNum[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int findNum[2] = {1, 0};
    
    for(int i = 0; i < answers.size(); ++i) {
        
        if(i % 5 + 1 == answers[i]) 
            ++correct[0];
        
        if(i % 2 == 1){
            if(findNum[0] >= 6) findNum[0] = 1;
            else if(findNum[0] == 2) ++findNum[0];
            if(findNum[0] == answers[i])
                ++correct[1];
            ++findNum[0];
        }
        else
            if(answers[i] == 2)
                ++correct[1];
        
        
        if(answers[i] == supozaThreeNum[findNum[1]])
            ++correct[2];
        ++findNum[1];
        if(findNum[1] == 10)
            findNum[1] = 0;
    }
    
    int maxNum = 0;
    for(int i = 0; i<3; ++i)
    {
        if(correct[i] > maxNum){
            maxNum = correct[i];
            result.clear();
            result.push_back(i+1);
        }
        else if(correct[i] == maxNum)
            result.push_back(i+1);
    }
    
    return result;
}