#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	string s;
	cin >> n >> s;
	
	int nums[26] = {};
	for (int i = 0; i < n; ++i) 
		cin >> nums[i];

	stack<double> st;
	double result = 0;

	for (int i = 0; i < s.length(); ++i) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			st.push(nums[s[i] - 'A']);
		}
		else {
			double num1 = st.top();
			st.pop();
			double num2 = st.top();
			st.pop();
			
			if (s[i] == '+')
				result = num1 + num2;
			else if (s[i] == '-')
				result = num2 - num1;
			else if (s[i] == '*')
				result = num1 * num2;
			else if (s[i] == '/')
				result = num2 / num1;

			st.push(result);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}