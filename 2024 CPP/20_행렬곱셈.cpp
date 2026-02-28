#include <iostream>
#include <vector>
using namespace std;
void matrix_mul() {
	int a = 0;
	int b = 0;
	int c = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	cin >> a >> b>> c;

	vector<vector<int>> matrix_1(a, vector<int>(b));
	vector<vector<int>> matrix_2(b, vector<int>(c));
	vector<vector<int>> matrix_3(a, vector<int>(c));

	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			cin >> matrix_1[i][j];
		}
	}

	for (i = 0; i < b; i++) {
		for (j = 0; j < c; j++) {
			cin >> matrix_2[i][j];
		}
	}

	for (i = 0; i < a; i++) {
		for (j = 0; j < c; j++) {
			for (k = 0; k < b; k++) {
				matrix_3[i][j] += matrix_1[i][k]*matrix_2[k][j];
			}
			cout << matrix_3[i][j] << " "; 
		}
		cout << endl;
	}

}
int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		matrix_mul();
	
	}
	return 0;

}