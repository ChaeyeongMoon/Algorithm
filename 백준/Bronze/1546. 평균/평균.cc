#include<iostream>
using namespace std;

int main() {
	double arr[1000];
	double sum = 0;
	int max = -1;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	for (int i = 0; i < N; i++) {
		sum += arr[i] / max * 100;
	}

	cout << sum / N << endl;
}