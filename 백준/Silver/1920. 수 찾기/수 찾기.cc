#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;
	vector<int>A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	sort(A.begin(), A.end());

	for (int i = 0; i < M; i++) {
		int start = 0;
		int end = A.size() - 1;
		int target;
		cin >> target;
		bool find = false;

		while (start <= end) {
			int midi = (start + end) / 2;
			int midv = A[midi];

			if (midv > target) {
				end = midi - 1;
			}
			else if (midv < target) {
				start = midi + 1;
			}
			else {
				find = true;
				break;
			}
		}
		if (find == true) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}