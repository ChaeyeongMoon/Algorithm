#include<iostream>
#include<vector>
using namespace std;

bool isClap(int num) {
	if ((num == 3) || (num == 6) || (num == 9)) {
		return true;
	}
	else return false;
}
int main() {
	int N;
	cin >> N;

	int A[1002];
	int count[1002] = { 0, };

	A[0] = 1;
	for (int i = 1; i <=N; i++) {
		A[i] = i;
	}

	int rest = 0;
	int check = 0;
	for (int i = 1; i <= N; i++) {
		int num = A[i];
		while (num != 0) {
			check = A[i];
			rest = num % 10;
			num = num / 10;
			if (isClap(rest)) {
				count[A[i]]++;
			}

		}
	}

	for (int i = 1; i <= N; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				cout << "-";
			}
			cout << " ";
		}
		else cout << i << " ";
	}
}