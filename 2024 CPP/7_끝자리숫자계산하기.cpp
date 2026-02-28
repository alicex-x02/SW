#include <iostream>
using namespace std;

int main() {
	int T = 0;
	int i, j = 0;

	cin >> T;
	for (i = 0; i < T; i++) {
		int n = 0;
		unsigned long long  sum = 1;
		cin >> n;

		for (j = 0; j < n; j++) {
			int num = 0;
			cin >> num;
			sum *= (num % 10);
			sum %= 10;
		}

		cout << sum << endl;

	}
	return 0;
}