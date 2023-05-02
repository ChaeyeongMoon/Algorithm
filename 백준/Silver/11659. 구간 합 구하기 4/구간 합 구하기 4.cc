#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int S[100001] = { 0 };

	for (int i = 1; i <=N; i++) {
		int A;
		cin >> A;
		S[i] =S[i-1] + A;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		cout << S[b] - S[a - 1]<<"\n";
	}
}