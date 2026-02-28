#include <iostream>
#include <vector>
using namespace std;
void matrix_test() {
	int m = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	cin >> m >> n;

	vector<vector<int>> matrix_1(m, vector<int>(n));
	vector<vector<int>> matrix_2(m, vector<int>(n));
	vector<vector<int>> matrix_3(m, vector<int>(n));

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> matrix_1[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			cin >> matrix_2[i][j];
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			matrix_3[i][j] = matrix_1[i][j] + matrix_2[i][j];
			cout << matrix_3[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		matrix_test();
	}

}