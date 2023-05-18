#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>row(100, 0);
vector<int>col(100, 0);
vector<int>cross(2, 0);
vector<vector<int>>A(100, vector<int>(100));
int main() {

	int T = 10;
	int N;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> A[i][j];
			}
		}

		for (int i = 0; i < 100; i++) {
			int rowsum = 0;
			for (int j = 0; j < 100; j++) {
				rowsum += A[i][j];
			}
			row[i] = rowsum;
		}

		for (int i = 0; i < 100; i++) {
			int colsum = 0;
			for (int j = 0; j < 100; j++) {
				colsum += A[j][i];
			}
			col[i] = colsum;
		}

		int rightcross = 0;
		for (int i = 0; i < 100; i++) {
			rightcross += A[i][i];
		}
		cross[0] = rightcross;

		int leftcross = 0;

		int addrow = 0;
		int addcol = 99;
		for (int i = 0; i < 100; i++) {
			leftcross += A[addrow][addcol];
			addrow++;
			addcol--;
		}
		cross[1] = leftcross;

		sort(col.begin(), col.end());
		sort(row.begin(), row.end());
		sort(cross.begin(), cross.end());

		int colmax = col[99];
		int rowmax = row[99];
		int crossmax = cross[1];

		int ans = max(colmax, max(rowmax, crossmax));



		cout << "#" << test_case << " ";
		cout << ans << "\n";

		//cout << "행: " << colmax << " 열: " << rowmax << " 대각선: " << crossmax << "\n";
	}
}