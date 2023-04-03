#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[1000];
	double max = 0;
	double sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	for (int i = 0; i < n; i++) {
		sum += arr[i] / max * 100;
	}
	double res = sum / n;
	cout << res;
}