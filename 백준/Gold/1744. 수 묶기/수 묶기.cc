
#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int>plusPq;//내림차순
	priority_queue<int, vector<int>, greater<int>>minusPq;//오름차순

	int zero = 0;
	int sum = 0;
	int one = 0;

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;

		if (data > 1) {
			plusPq.push(data);
		}
		else if (data == 1) {
			one++;
		}
		else if (data == 0) {
			zero++;
		}
		else {
			minusPq.push(data);
		}
	}

	while (plusPq.size() > 1) {
		int data1 = plusPq.top();
		plusPq.pop();
		int data2 = plusPq.top();
		plusPq.pop();
		sum += data1 * data2;

	}
	if (plusPq.empty() == false) {
		sum += plusPq.top();
		plusPq.pop();
	}

	while (minusPq.size() > 1) {
		int data1 = minusPq.top();
		minusPq.pop();
		int data2 = minusPq.top();
		minusPq.pop();

		sum += data1 * data2;
	}
	if (minusPq.empty() == false) {
		if (zero == 0) {
			sum += minusPq.top();
			minusPq.pop();
		}
	}

	sum += one;

	cout << sum << "\n";

}