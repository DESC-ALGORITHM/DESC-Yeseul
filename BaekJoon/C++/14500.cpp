#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int N, M, result = 0;
typedef pair<int, int> x_y;
queue<x_y> q;

int map[501][501];
int visited[501][501];

int rowTemp[] = {-1,1,0,0};
int colTemp[] = {0,0,1,-1};

bool isValid(int x, int y) {
    if (x >= 0 && x < M && y >= 0 && y < N)
		return true;
	else
		return false;
}

void dfs (int y, int x, int depth, int curNum) {
    if (depth == 4) {
        result = (result < curNum) ? curNum : result;
        return;
    }

        for (int i = 0; i < 4; i++) {
            int dx = x + rowTemp[i];
            int dy = y + colTemp[i];

            if (isValid(dx, dy) && !visited[dy][dx]) {
                visited[dy][dx] = 1;
                dfs(dy, dx, depth+1, curNum + map[dy][dx]);
                visited[dy][dx] = 0;
            }
        }

    // ㅗ, ㅜ, ㅓ, ㅏ 는 예외로 처리해줘야 함
    if(y-1 >= 0 && y+1 < N && x-1 >= 0) { //ㅓ
        result = max(result, (map[y-1][x] + map[y+1][x] + map[y][x] + map[y][x-1]));
    }
    if(y-1 >= 0 && y+1 < N && x+1 < M) { //ㅏ
        result = max(result, (map[y-1][x] + map[y+1][x] + map[y][x] + map[y][x+1]));
    }
    if(x-1 >= 0 && x+1 < M && y-1 < N) { //ㅗ
        result = max(result, (map[y][x-1] + map[y][x+1] + map[y][x] + map[y-1][x]));
    }
    if(x-1 >= 0 && x+1 < M && y+1 >= 0) { //ㅜ
        result = max(result, (map[y][x-1] + map[y][x+1] + map[y][x] + map[y+1][x]));
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            visited[y][x] = 1;
            dfs(y,x,1,map[y][x]);
            visited[y][x] = 0;
        }
    }

    cout << result << endl;


}