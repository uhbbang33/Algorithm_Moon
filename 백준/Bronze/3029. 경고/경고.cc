#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int curH, curM, curS, naH, naM, naS;
	char c;
	cin >> curH >> c >> curM >> c >> curS >> naH >> c >> naM >> c >> naS;
	
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