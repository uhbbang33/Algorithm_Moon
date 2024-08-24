#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string name = "";
	int age = 0, weight = 0;

	cin >> name >> age >> weight;
	while (name != "#" || age != 0 || weight != 0) {

		cout << name << " ";
		if (age > 17 || weight >= 80)
			cout << "Senior" << "\n";
		else
			cout << "Junior" << "\n";

		cin >> name >> age >> weight;
	}

	return 0;
}