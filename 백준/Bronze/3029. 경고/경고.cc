#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string curTime, naTime;
	cin >> curTime >> naTime;

	int curH = (curTime[0] - '0') * 10 + curTime[1] - '0';
	int naH = (naTime[0] - '0') * 10 + naTime[1] - '0';
	int curM = (curTime[3] - '0') * 10 + curTime[4] - '0';
	int naM = (naTime[3] - '0') * 10 + naTime[4] - '0';
	int curS = (curTime[6] - '0') * 10 + curTime[7] - '0';
	int naS = (naTime[6] - '0') * 10 + naTime[7] - '0';

	int resultH = naH - curH;
	int resultM = naM - curM;
	int resultS = naS - curS;

	if (resultS < 0) {
		resultS = resultS + 60;
		resultM -= 1;
	}
	if (resultM < 0) {
		resultM = resultM + 60;
		resultH -= 1;
	}
	if (resultH < 0)
		resultH = resultH + 24;

	string result = "";
	if (resultH < 10) 
		result += "0";
	result += to_string(resultH) + ":";
	if (resultM < 10)
		result += "0";
	result += to_string(resultM) + ":";
	if (resultS < 10)
		result += "0";
	result += to_string(resultS);

	if (result == "00:00:00")
		result = "24:00:00";

	cout << result;

	return 0;
}