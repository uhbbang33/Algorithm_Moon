#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    deque<int> sv;
    
    for(int i = 0; i < players.size(); ++i){
        for(int& t : sv){
            --t;
            
            if(t == 0)
                sv.pop_front();
        }
        
        while(players[i] >= m * (sv.size() +1) && players[i] >= m){
            sv.push_back(k);
            ++answer;
        }
        
        
    }
    
    return answer;
}