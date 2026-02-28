#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int T = 0;
	int i = 0;
	cin >> T;
	for (i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		cout << a + b << ' ' << a - b << ' ' << (a > b ? (a - b) : (b - a)) << ' ' << a * b << ' ' << a / b << ' ' << a % b << ' ' << (a > b ? a : b) << ' ' << int(a == b) << endl;
	}
	return 0;
}