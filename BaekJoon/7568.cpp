#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pair_int_int;

int main() {
	int N;
	cin >> N;

	vector<pair_int_int> v;

	for (int i = 0; i < N; i++) {
		int f, s;
        pair_int_int p;
		cin >> p.first >> p.second;

		v.push_back(p);
	}

	for (int i = 0; i < N; i++) {
		pair_int_int standard = v.at(i);
		int k = 0;

		for (int j = 0; j < N; j++) {
			if (j != i) {
				if (standard.first < v[j].first && standard.second < v[j].second)
					k++;
			}
		}

		cout << k + 1 << " ";
	}
}