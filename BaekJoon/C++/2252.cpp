#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)


int indegree[32001];
int n, m;
vector<int> connect[32001];
queue<int> answer;
queue<int> node;

int main() {
	scanf("%d %d", &n, &m);

	memset(indegree, 0, sizeof(indegree)); //indegree 

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		connect[a].push_back(b); // 가르키는 노드 벡터로 저장
		indegree[b]++; //진입 차수 높여주기
	}

	//시작 노드를 찾기
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
		{
			node.push(i);
			answer.push(i);
		}
	}

	while (!node.empty()) {
		int start = node.front(); node.pop();

		//연결된 노드를 모두 방문
		for (int i = 0; i < connect[start].size(); i++) {
			indegree[connect[start].at(i)]--;

			if (indegree[connect[start].at(i)] == 0) {
				node.push(connect[start].at(i));
				answer.push(connect[start].at(i));
			}
		}

	}

	//정답 출력
	for (int i = 0; i < n; i++) {
		printf("%d ", answer.front());
		answer.pop();
	}
}