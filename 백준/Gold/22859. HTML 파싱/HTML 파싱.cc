#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "";
	
	bool isTag = false;
	bool isTitle = false;
	bool isSentence = false;
	bool isEmpty = false;
	bool isStartSentence = false;

	char c;
	while (cin.get(c)) {
		// 공백 여러 개 처리
		if (isEmpty) {
			if (c == ' ')
				continue;
			else if (c != '<' && !isTag && !isStartSentence) {
				isEmpty = false;
				cout << " ";
			}
		}
		if (c == ' ' && isSentence && !isTag) {
			isEmpty = true;
			cout << s;
			s.clear();
			continue;
		}

		if (isStartSentence && c != ' ') {
			isStartSentence = false;
			isEmpty = false;
		}

		// 문장 출력, tag 지정
		if (isSentence && c == '<') {
			cout << s;
			s.clear();
			isTag = true;
		}
		else if (isSentence && c == '>')
			isTag = false;

		// 타이틀 출력
		if (isTitle && c == '"') {
			cout << "title : " << s << "\n";

			s.clear();
			isTitle = false;
			cin >> c;
			continue;
		}

		s += c;

		if (s == "</main>")
			break;
		else if (s == "<div title=\"") {
			isTitle = true;
			s.clear();
			continue;
		}
		else if (s == "<p>") {
			isSentence = true;
			isStartSentence = true;
		}
		else if (s == "</p>") {
			isSentence = false;
			isEmpty = false;
			cout << "\n";
		}
		
		if (s.front() == '<' && s.back() == '>')
			s.clear();
	}

	return 0;
}