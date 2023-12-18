#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> result;
    
    int correct[3] = {};
    
    int supozaTwoNum = 1;
    int supozaThreeNum[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int findNum = 0;
    
    for(int i = 0; i < answers.size(); ++i) {
        if(i % 5 + 1 == answers[i]) 
            ++correct[0];
        
        if(i % 2 == 1){
            if(supozaTwoNum >= 6) supozaTwoNum = 1;
            else if(supozaTwoNum == 2) ++supozaTwoNum;
            if(supozaTwoNum == answers[i]) ++correct[1];
            ++supozaTwoNum;
        }
        else if(answers[i] == 2)
                ++correct[1];
        
        if(answers[i] == supozaThreeNum[findNum])
            ++correct[2];
        ++findNum;
        if(findNum == 10) findNum = 0;
    }
    
    int maxNum = 0;
    for(int i = 0; i<3; ++i)
    {
        if(correct[i] > maxNum){
            maxNum = correct[i];
            result.clear();
        }
        if(correct[i] >= maxNum)
            result.push_back(i+1);
    }
    
    return result;
}