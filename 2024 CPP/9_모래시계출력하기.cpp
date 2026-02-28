#include <iostream>
#include <climits>
using namespace std;
void print_hourglass(int n) {
	int i, j, k = 0;
	for (i = 0; i < (n / 2) + 1; i++) {
		for (j = 0; j < i; j++) {
			cout << '-';
		}
		for (j = n - i; j > i; j--) {

			if ((j - i) % 2 != 0) {
				cout << '*';
			}
			else {
				cout << '+';
			}
		}
		for (j = 0; j < i; j++) {
			cout << '-';
		}
		cout << endl;
	}
	for (i = (n / 2) - 1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			cout << '-';
		}
		for (j = n - i; j > i; j--) {

			if ((j - i) % 2 != 0) {
				cout << '*';
			}
			else {
				cout << '+';
			}
		}
		for (j = 0; j < i; j++) {
			cout << '-';
		}
		cout << endl;
	}
}
int main() {
	int T, i = 0;
	int hourglass_size = 0;
	cin >> T;

	for (i = 0; i < T; i++) {
		cin >> hourglass_size;
		print_hourglass(hourglass_size);
	}


	return 0;
}