#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct GYS {
	string name;
	int kor, eng, math;
};

bool comp(GYS a, GYS b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math)
				return a.name < b.name;
			return a.math > b.math;
		}
		return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<GYS> v(n);

	for (int i = 0; i < n; ++i) 
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	
	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < n; ++i) 
		cout << v[i].name << "\n";


	return 0;
}