#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> ATM;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		ATM.push_back(tmp);
	}

	sort(ATM.begin(), ATM.end());

	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			result += ATM.at(j);
		}
	}

	cout << result;

	return 0;
}