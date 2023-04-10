#include<iostream>
using namespace std;

int checkArr[4];//비밀번호 체크 배열
int myArr[4];//현재 상태 배열
int checkSecret = 0;// 몇 개의 문자에 대한 개수를 충족했는지 판단하는 변수
void Add(char c);
void Remove(char c);
//S 문자열 크기 p 부분 문자열 크기
//A 문자열 데이터
//p 범위 0 부터 p-1만큼 배열 s 에적용하고 유효한 비밀번호인지 판단하기


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int S, P;//문자열 크기, 부분 문자열 크기
	cin >> S >> P;
	int result = 0;
	string A;//입력되는 문자열
	cin >> A;

	for (int i = 0; i < 4; i++) {//checkArr 배열에 값을 입력하는 코드
		cin >> checkArr[i];
		if (checkArr[i] == 0) {// 체크 배열의 원소가 0인 경우
			//해당 문자를 만족시키지 않아도 되므로 checkSecret을 하나 증가시킴
			checkSecret++;//문자열에서 몇개의 문자를 충족했는지 저장
		}
	}
	for (int i = 0; i < P; i++) {
		Add(A[i]);//입력되는 문자열을 처리
	}
	if (checkSecret == 4) {
		result++;
	}
	//슬라이딩 윈도우 처리 부분
	for (int i = P;i<S; i++) {//i는 현재 슬라이딩 윈도우의 끝. 부분문자열 길이만큼
		int j = i - P;//이전 윈도우의 시작부분(현재 슬라이딩 윈도우의 처음)
		//이전 윈도우의 끝지점(j)는 i에서 P만큼 떨어져 있음.
		//i에서 P만큼을 빼면 윈도우의 시작점이다.
		Add(A[i]);//Add로 새로운 문자를 추가하고
		Remove(A[j]);//Remove로 이전 문자를 제거하면서 부분 문자열의 범위를 이동시킴
		//4자리수에 대한 크기가 모두 충족되었을 때는 유효한 비밀번호
		if (checkSecret == 4) {//4개의 문자를 모두 충족했다면
			result++;//result를++
		}
	}
	cout << result << "\n";

}

void Add(char c) {//새로 들어온 문자열을 처리하는 함수
	switch (c) {
	case'A':
		myArr[0]++;
		if (myArr[0] == checkArr[0])//현재 창문 배열원소A와 체크알파벳 배열원소 같다면
			checkSecret++;//A 한개 충족++
		break;

	case 'C':
		myArr[1]++;
		if (myArr[1] == checkArr[1])//현재 창문 배열원소A와 체크알파벳 배열원소 같다면
			checkSecret++;//A 한개 충족++
		break;
	case 'G':
		myArr[2]++;
		if (myArr[2] == checkArr[2])//현재 창문 배열원소A와 체크알파벳 배열원소 같다면
			checkSecret++;//A 한개 충족++
		break;
	case 'T':
		myArr[3]++;
		if (myArr[3] == checkArr[3])//현재 창문 배열원소A와 체크알파벳 배열원소 같다면
			checkSecret++;//A 한개 충족++
		break;
	}
}

void Remove(char c) {//제거할 문자를 처리하는 함수
	switch (c) {
	case'A':
		if (myArr[0] == checkArr[0])//현재 창문 배열원소A와 체크알파벳 배열원소 같다면
			checkSecret--;//A 한개 충족++
		myArr[0]--;
		break;

	case 'C':
		if (myArr[1] == checkArr[1])//현재 창문 배열원소A와 체크알파벳 배열원소 같다면
			checkSecret--;//A 한개 충족++
		myArr[1]--;
		break;
	case 'G':
		if (myArr[2] == checkArr[2])//현재 창문 배열원소A와 체크알파벳 배열원소 같다면
			checkSecret--;//A 한개 충족++
		myArr[2]--;
		break;
	case 'T':
		if (myArr[3] == checkArr[3])//현재 창문 배열원소A와 체크알파벳 배열원소 같다면
			checkSecret--;//A 한개 충족++
		myArr[3]--;
		break;
	}
}