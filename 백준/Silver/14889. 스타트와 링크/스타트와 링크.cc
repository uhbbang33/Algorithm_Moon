#include <iostream>
using namespace std;

#define MAX_RESULT 1000000000

int n;
int arr[21][21]{};
bool isSelected[21]{};
int result = MAX_RESULT;

void CalculatePowerDiff() {
	int startTeamPower = 0;
	int linkTeamPower = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (isSelected[i] && isSelected[j])
				startTeamPower += arr[i][j];
			else if (!isSelected[i] && !isSelected[j])
				linkTeamPower += arr[i][j];
		}
	}

	result = min(result, abs(startTeamPower - linkTeamPower));
}

void SelectMember(int cnt, int cur) {
	if (cnt == n / 2) {
		CalculatePowerDiff();
		return;
	}

	for (int i = cur + 1; i < n; ++i) {
		if (!isSelected[i]) {
			isSelected[i] = true;
			SelectMember(cnt + 1, i);
			isSelected[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	SelectMember(0, -1);

	cout << result;

	return 0;
}