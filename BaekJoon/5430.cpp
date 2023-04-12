#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
    int T, n; 

    cin >> T;

    for(int t = 0; t < T; t++) {
        string p, arr;
        bool reverse = false;
        bool error = false;
        deque<int> deq;
        

        cin >> p;
        cin >> n;
        cin >> arr;

        string s = ""; // 숫자가 일의 숫자가 아닐 수 있으니까, ex) [35,6]
        for(int i = 0; i < arr.length(); i++) {

            if (isdigit(arr[i])) {
                s += arr[i];
            }
            else {
                if (!s.empty()) {
                    deq.push_back(stoi(s));
                    s = "";
                }
            }
        }
        

        for (int j = 0; j < p.length() ; j++ ) {
            if (p[j]=='R') {
                reverse = !reverse; // 뒤집었는지 토글로 저장
            }
            else {
                if (deq.empty()) {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if (reverse) deq.pop_back();
                else deq.pop_front();
            }
        }


        // 출력
        if (!error) {
            cout << "[";
            while (!deq.empty())
            {
                if (reverse) {
                    if (deq.size()==1){
                        cout << deq.back();
                        deq.pop_back();
                    }

                    else {
                        cout << deq.back() << ",";
                        deq.pop_back();
                    }

                }

                else {
                    if (deq.size()==1){
                        cout << deq.front();
                        deq.pop_front();
                    }

                    else {
                        cout << deq.front() << ",";
                        deq.pop_front();
                    }
                }
            }
            cout << "]" << endl;
        }
    }
    return 0;
}