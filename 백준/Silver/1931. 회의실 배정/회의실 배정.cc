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


//
//#include<iostream>
//#include<vector>
//#include<algorithm>
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
//	vector<pair<int, int>>A(N);
//
//	for (int i = 0; i < N; i++) {//종료시간 정렬 우선을 위해 종료값을 first에 저장
//		cin >> A[i].second;
//		cin >> A[i].first;
//	}
//
//	sort(A.begin(), A.end());//종료시간기준 오름차순으로 정렬됨
//
//	int count = 0;
//	int end = -1;
//
//	for (int i = 0; i < N; i++) {
//		if (A[i].second >= end) {
//			//시작시간이 종료시간보다 커서 겹치지 않는 다음 회의가 나온 경우
//			end = A[i].first;//종료시간을 회의종료시간으로 업데이트
//			count++;
//		}
//	}
//
//	cout << count << "\n";
//}





#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>>A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i].second;
		cin >> A[i].first;
	}
	sort(A.begin(), A.end());

	int cnt = 0;
	int end = -1;

	for (int i = 0; i < N; i++) {
		if (A[i].second >= end) {
			cnt++;
			end = A[i].first;
		}
	}
	cout << cnt << "\n";
}