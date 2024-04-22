#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = n - 1;
    
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j*j <= i; ++j){
            if(i % j == 0) {
                --answer;
                break;
            }
        }
    }
    
    return answer;
}