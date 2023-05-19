#include<iostream>
#include<queue>
using namespace std;

int main() {

	int test_case;

	for (test_case = 1; test_case <= 10; test_case++) {
		int tmp;
		queue<int>q;
		int n;
		cin >> n;

		for (int i = 0; i < 8; i++) {
			cin >> tmp;
			q.push(tmp);
		}
			int cycle = 1;

			while (1) {
				int num = q.front() - cycle;
				q.pop();
				if (num <= 0)break;

				q.push(num);

				
				cycle++;
				
				if (cycle > 5) {
					cycle = 1;
				}
			}
			q.push(0);
		

		
		cout << "#" << test_case << " ";
		while (!q.empty()) {
			cout << q.front()<<" ";
			q.pop();
		}
		cout << "\n";
	}
	
}