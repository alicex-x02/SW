#include <iostream>
using namespace std;

int main() {
	int T = 0;
	int i = 0;
	cin >> T;
	for (i = 0; i < T; i++) {
		int k, a, b = 0;
		cin >> k;
		for (a = 1; a < k + 1; a++) {
			int ans = a;
			for (b = 1; b <= a; b++) {
				cout << ans << " ";
				ans = ans + k - b;
			}
			cout << endl;
		}

	}
	return 0;
}