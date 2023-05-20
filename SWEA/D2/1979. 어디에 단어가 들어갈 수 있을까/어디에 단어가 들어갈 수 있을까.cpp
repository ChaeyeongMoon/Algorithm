#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int test_case;
	
	for (test_case = 1; test_case <= T; test_case++) {
		int N, K;
		cin >> N >> K;
		int result = 0;
		int A[15][15];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> A[i][j];
			}
		}

		
		for (int i = 0; i < N; i++) {
			int rowcnt = 0;
			for (int j = 0; j < N; j++) {
				if (A[i][j] == 1) {
					rowcnt++;
					if (rowcnt > K) {
						rowcnt = 0;
					}
					if (j == N - 1 && rowcnt == K) {
						result++;
					}
				}
				else {
					if (rowcnt == K) {
						result++;
					}
					rowcnt = 0;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			int rowcnt = 0;
			for (int j = 0; j < N; j++) {
				if (A[j][i] == 1) {
					rowcnt++;
					if (rowcnt > K) {
						rowcnt = 0;
					}
					if (j == N - 1 && rowcnt == K) {
						result++;
					}
				}
				else {
					if (rowcnt == K) {
						result++;
					}
					rowcnt = 0;
				}
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}
}