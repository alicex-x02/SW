#include <iostream>
#include <cmath>
using namespace std;
int main() {	//ÃÖºó¼ö
	int t, i = 0;
	cin >> t;
	for (i = 0; i < t; i++) {
		int arr[101] = { 0, };
		int max_freq = 0;;
		int max_num = 0;
		while (true) {
			int num = 0;
			cin >> num;
			if ((num >= 1) && (num <= 100)) {
				arr[num]++;
			}
			else if (num == 0) {
				break;
			}
		}
		for (int j = 1; j <= 100; j++) {
			if (arr[j] > max_freq) {
				max_freq = arr[j];
				max_num = j;
			}
			else if (arr[j] == max_freq && j > max_num) {
				max_num = j;
			}
		}
		if (max_freq == 0) {
			cout << 0 << endl;
		}
		else {
			cout << max_num << endl;
		}

	}
}