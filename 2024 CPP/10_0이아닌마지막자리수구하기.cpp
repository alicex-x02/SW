#include <iostream>
using namespace std;
void last_number(int num) {
	int i, j = 0;
	int input = 0;
	int zero_count = 0;
	int last_num = 1;
	int two_count = 0;
	int five_count = 0;
	for (i = 0; i < num; i++) {
		cin >> input;
		while (input % 2 == 0) {
			two_count++;
			input /= 2;
		}
		while (input % 5 == 0) {
			five_count++;
			input /= 5;
		}
		if (input != 1) {
			last_num = (last_num * (input % 10)) % 10;
		}
	}
	zero_count = min(two_count, five_count);


	if (two_count > zero_count) {
		for (int j = 0; j < two_count - zero_count; j++) {
			last_num = (last_num * 2) % 10;
		}
	}
	else if (five_count > zero_count) {
		for (int j = 0; j < five_count - zero_count; j++) {
			last_num = (last_num * 5) % 10;
		}
	}
	cout << last_num << ' ' << zero_count << endl;
}
int main() {
	int t, i = 0;
	cin >> t;
	for (i = 0; i < t; i++) {
		int num = 0;
		cin >> num;
		last_number(num);
	}
}