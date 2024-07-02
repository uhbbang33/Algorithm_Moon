#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int visitCnt[13]{};
	bool visited[13]{};

	pair<int, int> p;
	int caseCnt = 1;
	
	int nodeCnt = 0;
	while (1) {
		cin >> p.first >> p.second;

		if (p.first == -1 && p.second == -1)
			break;
		else if (p.first == 0 && p.second == 0)
		{
			bool isTree = true;
			int rootCnt = 0;
			for (int i = 0; i < 13; ++i) {
				if (visitCnt[i] > 1) {
					isTree = false;
					break;
				}

				if (visited[i] == true && visitCnt[i] == 0)
					++rootCnt;
			}
			for (int i = 0; i < 13; ++i) {
				visitCnt[i] = 0;
				visited[i] = false;
			}
			
			if (isTree && (rootCnt == 1 || nodeCnt == 1)) 
				cout << "Case " << caseCnt << " is a tree." << "\n";
			else 
				cout << "Case " << caseCnt << " is not a tree." << "\n";

			++caseCnt;
			nodeCnt = 0;
		}

		visited[p.first] = true;
		visited[p.second] = true;
		++visitCnt[p.second];
		++nodeCnt;

	}

	return 0;
}