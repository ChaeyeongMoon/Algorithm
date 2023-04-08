#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	
	int count = 0;

	vector<int>A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	for (int k = 0; k < N; k++) {
		long find = A[k];//찾고자 하는 값
		int begin = 0;
		int last = N - 1;

		while (begin < last) {
			if (A[begin] + A[last] == find) {//좋은 수를 찾은 경우, 서로 다른 두 수의 합인지 체크
				if (begin != k && last != k) {
					count++;
					break;
				}
				else if (begin == k) {
					begin++;
				}
				else if (last == k) {
					last--;
				}
			}
			else if (A[begin] + A[last] < find) {
				begin++;
			}
			else {
				last--;
			}
			
		}
	}
	cout << count << "\n";
}