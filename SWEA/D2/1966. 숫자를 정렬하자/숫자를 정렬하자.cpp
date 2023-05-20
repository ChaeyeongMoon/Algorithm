#include<iostream>
#include<queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	int test_case;

	for (test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;
		priority_queue<int,vector<int>,greater<int>>q;
		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			q.push(data);
		}

		cout << "#" << test_case << " ";
		while (!q.empty()) {
			cout << q.top() << " ";
			q.pop();
		}
		cout << "\n";
	}
}