#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sosucal(int input) {
	if (input < 2)return false;
	for (int i = 2; i * i <= input; i++) {
		if (input % i == 0)return false;
	}
	return true;
}

int main() {
	int a, b;
	vector<int>sosu;
	cin >> a >> b;
	int sum = 0;

	for (int i = a; i <= b; i++) {
		if (sosucal(i))sosu.push_back(i);
	}

	if (sosu.empty())cout << "-1" << endl;
	else {
		for (int i = 0; i < sosu.size(); i++) {
			sum += sosu[i];
		}
		cout << sum << endl;
		sort(sosu.begin(),sosu.end());
		cout << sosu[0] << endl;
	}

}