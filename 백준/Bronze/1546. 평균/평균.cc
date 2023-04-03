#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	double arr[1000];
	int max = -1;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	for (int i = 0; i < n; i++) {
		sum += arr[i]/max*100;
	}
	cout << sum / n;
}

///double형 때매 틀림