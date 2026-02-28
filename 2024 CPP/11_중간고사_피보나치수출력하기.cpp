#include <iostream>
using namespace std;
void fibo() {
	int n = 0;
	int i = 0;
	long long int sum = 1;
	long long int sum_before = 0;
	long long int tmp = 0;
	int arr[50];
	cin >> n;
	for (i = 1; i < n; i++) {
		tmp = sum + sum_before;
		sum_before = sum;
		sum = tmp;
	}
	if (n == 1) {
		cout << 1 << endl;
	}
	else {
		cout << tmp << endl;
	}

}
int main() {
	int t = 0;
	int i = 0;

	cin >> t;
	for (i = 0; i < t; i++) {
		fibo();
	}

}