#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    int tmp;
    vector<int> cnt;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> tmp;
        cnt.push_back(tmp);
    }

    sort(cnt.begin(), cnt.end());

    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> tmp;
        cout << upper_bound(cnt.begin(), cnt.end(), tmp) - lower_bound(cnt.begin(), cnt.end(), tmp) << " ";
    }

}

