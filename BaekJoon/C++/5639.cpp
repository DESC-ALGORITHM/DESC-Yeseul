#include <iostream>
#include <vector>
using namespace std;
int tree[10000];

void postOrder(int start, int end) { // left - right - root
	if (start >= end) {
		return;
	}
	if (start == end - 1) {
		cout << tree[start] << '\n';
		return;
	}
	int idx = start + 1;
	while (idx<end) {
		if (tree[start]<tree[idx]) { // 큰게 나오기 전까지 계속 left 노드
			break;
		}
		idx++;
	}
	
	postOrder(start+1, idx);
	postOrder(idx, end);
	cout << tree[start] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int num;
	int index = 0;

	while (cin >> num) {
		tree[index++] = num;
	}

	postOrder(0,index);

	return 0;
}