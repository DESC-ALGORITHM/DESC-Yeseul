#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string words[10];
map<char, int> alpha;
int alphaCount[26] = {0};
int alphaScore[26];
int n; int result=0;
typedef pair<char, int> char_int;

bool cmp(const char_int& a, const char_int& b) {
        char ch1 = a.first;
        char ch2 = b.first;

        if (alphaCount[ch1 - 'A'] > alphaCount[ch2 - 'A'])
            return true;
        else
            return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> words[i];

        for (int j = 0; j < words[i].length(); j++) {
            int num = words[i].length() - j; //{}의 자리 ex) 만의 자리
            int ch = words[i].at(j);

            alphaCount[ch - 'A'] += pow(10, num-1); //ch가 나온 횟수

            if (alpha.find(ch) == alpha.end()) //없는 알파벳이라면
                alpha.insert(char_int(ch, num));
            else
                if (alpha.at(ch) < num)
                    alpha.at(ch) = num;
        }
    }
    
    //map에서 value 값으로 정렬 해야하므로 vector로 옮겨서
    vector<char_int> alphaVector(alpha.begin(), alpha.end());
    sort(alphaVector.begin(), alphaVector.end(), cmp);

    //알파벳에 숫자 할당하기
    for (int i = 0; i < alphaVector.size(); i++) {
        alphaScore[alphaVector[i].first -'A'] = 9 - i;
    }

    for (int i = 0; i < n; i++) {
        string word = words[i];

        for (int j = 0; j < word.length(); j++) {
            int digit = word.length() - j;
            result += alphaScore[word.at(j) - 'A'] * pow(10, digit-1);
        }
    }

    cout << result << endl;

    return 0;
}