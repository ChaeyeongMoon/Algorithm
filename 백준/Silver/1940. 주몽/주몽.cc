#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int begin = 0;
	int last = N - 1;
	int count = 0;

	vector<int>A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	while (begin < last) {
		if (A[begin] + A[last] < M) {
			begin++;
		}
		else if (A[begin] + A[last] > M) {
			last--;
		}
		else {
			count++;
			begin++;
			last--;
		}
	}
	cout << count << "\n";
}