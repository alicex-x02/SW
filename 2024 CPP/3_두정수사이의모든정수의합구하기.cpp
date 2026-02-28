#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int T = 0;
	int i, j = 0;



	cin >> T;
	for (i = 0; i < T; i++) {
		int M, N = 0;
		int sum = 0;
		cin >> M >> N;
		for (j = M; j <= N; j++) {
			sum += j;
		}
		cout << sum << "\n";

	}
	return 0;
}