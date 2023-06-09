////#include<iostream>
////#include<queue>
////#include<vector>
////using namespace std;
////
////static vector<int>parent;
////void unionfunc(int a, int b);
////int find(int a);
////bool checkSame(int a, int b);
////
////int main() {
////	ios::sync_with_stdio(false);
////	cin.tie(NULL);
////	cout.tie(NULL);
////
////	int N, M;
////	cin >> N >> M;
////
////	vector<vector<int>>A;
////	vector<int>indegree;
////	A.resize(N + 1);
////	indegree.resize(N + 1);
////
////	for (int i = 0; i < M; i++) {
////		int s, e;
////		cin >> s >> e;
////
////		A[s].push_back(e);
////		indegree[e]++;//진입차수 배열 데이터 저장
////	}
////	queue<int>queue;//위상 정렬 수행
////
////	for (int i = 1; i <= N; i++) {
////		if (indegree[i] == 0) {
////			queue.push(i);
////		}
////	}
////	while (!queue.empty()) {
////		int now = queue.front();
////		queue.pop();
////		cout << now << " ";
////		for (int next : A[now]) {
////			indegree[next]--;
////			if (indegree[next] == 0) {
////				queue.push(next);
////			}
////		}
////	}
////}
//
//
//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N;
//	cin >> N;
//
//	priority_queue<int, vector<int>,greater<int>>pq;//오름차순 정렬
//	//(타입), (컨테이너) vector<int>기반으로 만들고, (비교)작은 원소가 높은 우선순위
//	int data;
//
//	for (int i = 0; i < N; i++) {
//		cin >> data;
//		pq.push(data);
//	}
//
//	int data1 = 0;
//	int data2 = 0;
//	int sum = 0;
//
//	while (pq.size() != 1) {
//		data1 = pq.top();//가장 작은 수가 top으로 반환됨
//		pq.pop();//반환한거 없앰
//		data2 = pq.top();//두 번째로 작은 수 반환
//		pq.pop();
//		sum += data1 + data2;
//		pq.push(data1 + data2);
//	}
//	cout << sum << "\n";
//}



#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;
	int data;

	priority_queue<int, vector<int>, greater<int>>pq;

	for (int i = 0; i < N; i++) {
		cin >> data;
		pq.push(data);
	}

	int data1 = 0;
	int data2 = 0;
	int sum = 0;
	while (pq.size() != 1) {
		data1 = pq.top();
		pq.pop();
		data2 = pq.top();
		pq.pop();
		sum += data1 + data2;
		pq.push(data1+data2);
	}
	cout << sum << "\n";
}