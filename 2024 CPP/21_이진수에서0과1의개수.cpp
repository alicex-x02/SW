#include <iostream>
#include <bitset>
using namespace std;
void binary_count() {
	int one_count = 0;
	int zero_count = 0;
	int num_dec = 0;
	int start = -1;
	int i = 0;
	cin >> num_dec;
	bitset<32> num_bi(num_dec);
	for (i = 31; i >= 0; i--) {
		if (num_bi[i] == 1) {
			start = i;
			break;
		}
	}
	if (start== -1) {
		cout << 0 << " " << endl;
		return;
	}
	for (i = start; i>=0; i--) {
		if (num_bi[i] == 1) {
			one_count++;
		}
		else {
			zero_count++;
		}
	}


	cout << zero_count << " " << one_count << endl;

}
int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		binary_count(); 
	}
	return 0;
}