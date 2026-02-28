#include <iostream>
using namespace std;

int main() {
	int tc, n, digit_cnt, base;
	cin >> tc;

	while (tc--) {
		digit_cnt = 1;
		base = 9;
		cin >> n;
		while (n > digit_cnt * base) {
			n -= digit_cnt * base;
			digit_cnt++;
			base *= 10;
		}
		int number = (base / 9) + (n - 1) / digit_cnt;
		for (int i = 0; i < digit_cnt - ((n - 1)%2)-1; i++){
			number /= 10;
		}
		cout << number % 10 << endl;
	}
	return 0;
}