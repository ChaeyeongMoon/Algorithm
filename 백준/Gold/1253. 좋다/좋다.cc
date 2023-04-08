#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int>A(N, 0);
	int count = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	for (int k = 0; k < N; k++) {
		int find = A[k];
		int start = 0;
		int last = N - 1;

		while (start < last) {
			if (A[start] + A[last] == find) {
				if (start != k && last != k) {
					count++;
					break;
				}
				else if (start == k) {
					start++;
				}
				else if (last == k) {
					last--;
				}
			}
			else if (A[start] + A[last] > find) {
				last--;
			}
			else {
				start++;
			}
		}
	}

	cout << count << "\n";
}