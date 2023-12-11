#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string date[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int num = b - 1;
    
    if( a > 1) num += 31;
    if(a > 2 )num += 29;
    if(a > 3) num += 31;
    if(a > 4) num += 30;
    if(a > 5) num += 31;
    if(a > 6) num += 30;
    if(a > 7) num += 31;
    if(a > 8) num += 31;
    if(a > 9) num += 30;
    if(a > 10) num += 31;
    if(a > 11) num += 30;
    
    answer = date[num % 7];
        
    return answer;
}