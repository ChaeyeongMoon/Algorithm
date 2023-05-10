#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int count = 0;
	for (int k = 0; k < N; k++) {
		int i = 0;
		int j = N - 1;
		int find = A[k];

		while (i < j) {
			if (A[i] + A[j] == find) {
				if (i != k && j != k) {
					count++;
					break;
				}
				else if (i == k) {
					i++;
				}
				else if (j == k) {
					j--;
				}
			}
			else if (A[i] + A[j] > find) {
				j--;
			}
			else {
				i++;
			}
		}
	}
	cout << count << "\n";
}