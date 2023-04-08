#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;

	long S[1000001] = { 0 };//합 배열
	long C[1000001] = { 0 };//같은 나머지 갖는 인덱스 카운트 배열
	long answer = 0;

	cin >> S[0];

	for (int i = 1; i < N; i++) {
		int temp = 0;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}
	for (int i = 0; i < N; i++) {//합배열에 M으로 나눗셈 연산하기
		int remainder = S[i] % M;//합배열을 M으로 나눈 나머지 값
		if (remainder == 0) {
			answer++;
		}
		C[remainder]++;//나머지가 같은 인덱스의 갯수 세기
	}
	for (int i = 0; i < M; i++) {
		if (C[i] > 1) {
			//나머지가 같은 인덱스 중 2개 뽑는 경우의 수 더하기
			answer = answer + (C[i] * (C[i] - 1) / 2);
			//C[i]개 중에 2개를 뽑는 경우의 수 계산 공식: C[i] * (C[i] - 1) / 2
		}
	}
	cout << answer << "\n";
}