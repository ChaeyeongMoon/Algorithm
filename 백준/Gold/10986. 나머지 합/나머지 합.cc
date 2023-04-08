#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	long ans = 0;
	long S[1000001] = { 0 };
	long C[1000001] = { 0 };

	cin >> S[0];
	
	for (int i = 1; i < N; i++) {
		int temp = 0;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < N; i++) {
		int remainder = S[i] % M;
		if (remainder == 0) {
			ans++;
		}
		C[remainder]++;
	}

	for (int i = 0; i < N; i++) {
		if (C[i] > 1) {
			ans = ans + (C[i] * (C[i] - 1) / 2);
		}
	}
	cout << ans << "\n";
}