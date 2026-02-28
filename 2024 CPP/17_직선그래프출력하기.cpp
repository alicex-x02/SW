#include <iostream>

using namespace std;
void linear_graph() {
	int k = 0;
	cin >> k;

	int i = 0;
	int j = 0;

	for (i = 0; i < (k - 1) / 2; i++) {
		for (j = 0; j < k; j++) {
			if (j == k - i - 1) {
				cout << "*";
			}
			else if (j == (k - 1) / 2) {
				cout << "I";
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}


	for (i = 0; i < k; i++) {
		if (i == (k - 1) / 2) {
			cout << "O";
		}
		else {
			cout << "+";
		}
	}
	cout << endl;
	for (i = 0; i < (k - 1) / 2; i++) {
		for (j = 0; j < k; j++) {
			if (j == (k / 2) - i - 1) {
				cout << "*";
			}
			else if (j == (k - 1) / 2) {
				cout << "I";
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}

}
int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		linear_graph();
	}
}