#include<iostream>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int S[100001];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		S[i + 1] = S[i] + A;
	}

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << S[e] - S[s - 1] << '\n';
	}
}