#include <iostream>
#include <vector>
#include <string>
using namespace std;
void num_count() {
	int k = 0;
	long long len = 9;
	int digit = 1;
	long long start = 1;

	cin >> k;

	while (k > len * digit) {
		k -= len * digit;
		len *= 10;
		start *= 10;
		digit++;
	}
	long long number = start + (k - 1) / digit;
	int index = (k - 1) % digit;

	string num_str = to_string(number);
	cout << num_str[index] << endl;


}
int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		num_count();
	}
	return 0;
}