#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	
	// 처음 시작은 세트 한개로
	int set_cnt = 1;

	cin >> N;

	vector<int> char_cnt(10);
	fill(char_cnt.begin(), char_cnt.end(), 0);

	for (int i = 0; i < N.length(); i++) {
		int num = N[i] - '0';
		char_cnt[num]++;

		// 숫자가 가지고 있는 세트에 있는 수보다 더 필요하므로 세트를 +1
		if (char_cnt[num] > set_cnt) {

			if ((num == 6) || (num == 9)) {
				if (num == 6) { // 9로 대체 가능하므로 9의 갯수도 확인
					if (char_cnt[9] + 1 > set_cnt) {
						set_cnt++;
					}	
					char_cnt[num]--;
					char_cnt[9]++;
				}
				else if (num == 9) {
					if (char_cnt[6] + 1 > set_cnt) {
						set_cnt++;
					}
					char_cnt[num]--;
					char_cnt[6]++;
				}
			}
			else {
				set_cnt++;
			}
		}
	}

	cout << set_cnt << endl;
}