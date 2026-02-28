#include <iostream>
#include <cmath>
using namespace std;
void triangle() {
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a >> b >> c;
	if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
		cout << 0 << endl;
		return;
	}
	if ((a == b) && (b == c) && (a == c)) {
		cout << 1 << endl;
	}
	else if ((pow(a, 2) + pow(b, 2) == pow(c, 2)) || (pow(a, 2) + pow(c, 2) == pow(b, 2)) || (pow(c, 2) + pow(b, 2) == pow(a, 2))) {
		cout << 2 << endl;
	}

	else if ((a == b) || (b == c) || (a == c)) {
		cout << 3 << endl;
	}
	else {
		cout << 4 << endl;
	}
}
int main() {
	int t, i = 0;
	cin >> t;
	for (i = 0; i < t; i++) {
		triangle();
	}
}