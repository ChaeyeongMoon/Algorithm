#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

static vector<vector<int>>edge;
static vector<bool>visited;

void DFS(int node);
void BFS(int node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	edge.resize(N + 1);
	visited = vector < bool>(N + 1, false);
	
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		edge[s].push_back(e);
		edge[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) {
		sort(edge[i].begin(), edge[i].end());
	}

	DFS(V);
	visited = vector<bool>(N + 1, false);
	cout << "\n";
	BFS(V);
}

void DFS(int node) {
	cout << node << " ";
	visited[node] = 1;
	for (int i : edge[node]) {
		if (visited[i] == false) {
			DFS(i);
			//visited[i] = true;
		}
	}
}

void BFS(int node) {
	queue<int>q;
	q.push(node);
	visited[node] = true;
	while (q.size()) {
		cout << q.front() << " ";
		for (int i : edge[q.front()]) {
			if (visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
	}
}


//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int visiteddfs[1001];
//int visitedbfs[1001];
//
//vector<int>edge[1001];
//
//void dfs(int node) {
//	cout << node << " ";
//	visiteddfs[node] = 1;
//	for (auto x : edge[node]) {
//		if (visiteddfs[x] != 1) {//방문이 안 되어있으면
//			dfs(x);
//		}
//	}
//	
//}
//
//void bfs(int node) {
//	queue<int>q;
//	q.push(node);
//	visitedbfs[node] = 1;//첫 노드를 방문했다고 표시
//	while (q.size()) {//큐에 뭔가 남아있다몀ㄴ
//		cout << q.front() << " ";
//		for (auto x : edge[q.front()]) {
//			if (visitedbfs[x] != 1) {
//				visitedbfs[x] = 1;
//				q.push(x);
//			}
//		}
//		q.pop();//방금 살펴본 정점을 큐에서 빼준다
//	}
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//
//	int v;
//	cin >> v;
//
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//
//		edge[a].push_back(b);
//		edge[b].push_back(a);
//
//	}
//	dfs(v);
//	cout << "\n";
//	bfs(v);
//}