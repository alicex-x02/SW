#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc, num, cnt_0, cnt_1;
	cin >> tc;
	while (tc--) {
		cin >> num;
		cnt_0 = 0, cnt_1 = 0;

		while (num) {
			if (num % 2) {
				cnt_1++;
			}
			else {
				cnt_0++;
			}
			num /= 2;

		}
		cout << cnt_0 << ' ' << cnt_1 << endl;

	}

	return 0;

}