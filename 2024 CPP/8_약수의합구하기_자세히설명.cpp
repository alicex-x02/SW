#include <iostream>
using namespace std;

void getNumberOfDivisor(int num) {
	int i, count = 0;
	int sum = 0;
	for (i = 1; i * i <= num; i++) {
		if (num % i == 0) {
			sum += i;
			count++;
			if ((i != num / i) && (num / i != num)) {
				sum += num / i;
				count++;
			}
		}
	}

	cout << count << " " << sum << endl;
}
int main() {
	int t, i = 0;
	cin >> t;
	for (i = 0; i < t; i++) {
		int num = 0;
		cin >> num;
		getNumberOfDivisor(num);
	}
}