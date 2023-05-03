#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int N, M;
	vector<int> trees;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		trees.push_back(tmp);
	}

	//정렬하기
	sort(trees.begin(), trees.end());

	//이분 탐색으로 H값 찾기
	int row=0; long long high=trees.at(N-1); int middle;

	while (row <= high) {
		long long gotten_tree = 0;
		middle = (row + high) / 2;

		for (int i = 0; i < N; i++) {
			if (trees.at(i) > middle)
			{
				gotten_tree += trees.at(i) - middle;
			} 
		}

		if (gotten_tree < M) {
			high = middle - 1;
		}
		else {
			row = middle + 1;
		}
	}

	cout << high << endl;

}