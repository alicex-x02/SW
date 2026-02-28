#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T = 0;
	int i, j = 0;

	cin >> T;
	for (i = 0; i < T; i++) {
		int num = 0;
		cin >> num;
		vector<int>input(num);
		for (j = 0; j < num; j++) {
			cin >> input[j];
		}
		int max = input[0];
		int min = input[0];
		for (j = 0; j < num; j++) {
			if (max < input[j]) {
				max = input[j];
			}
			if (min > input[j]) {
				min = input[j];
			}
		}
		cout << max << " " << min << "\n";
	}
	return 0;
}