#include <iostream>
using namespace std;
 
int main(void){
 
    int n;
    cin >> n;

    int count =0;
 
    for (int i = 0; i < n; i++) {

        string str;
        bool isRight = true;
        bool alpabet[26] = {false};

        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {
            int point = j;
            int idx = str[j] - 'a';

            if (!alpabet[idx]) {
                alpabet[idx] = true;
                char now = str[j];

                while (( point+1 < str.length()) && (now == str[point+1]))
                {
                    point++;
                }
                
            }
            else {
                isRight = false;
                break;
            }

            j = point;
        }

        if (isRight) {
            count++;
        }

    }
    cout << count << endl;
 
    return 0;
}
