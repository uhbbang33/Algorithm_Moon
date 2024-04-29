#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {

	int N = 0; 
	cin >> N;
	
	stack<int> st;
	string s;
	int num = 0;

	for (int i = 0; i < N; ++i) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			st.push(num);
		}
		else if (s == "pop") {
			if (st.empty())
				cout << "-1" << endl;
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (s == "top") {
			if (st.empty())
				cout << "-1" << endl;
			else
				cout << st.top() << endl;
		}
		else if (s == "size")
			cout << st.size() << endl;
		else if (s == "empty") {
			if (st.empty())
				cout << "1" << endl;
			else cout << "0" << endl;
		}
	}

	return 0;
}