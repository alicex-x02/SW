#include <iostream>
using namespace std;

int main() {
	int t = 0;
	int size = 0;
	int repeat_count = 0;
	int tmp = 0;
	cin >> t;
	while (t--) {
		cin >> size >> repeat_count;
		int* current = new int[size + 2] {0};
		int* next = new int[size + 2] {0};

		for (int i = 1; i <= size; i++) {
			cin >> current[i];
		}

		while (repeat_count--) {
			for (int i = 1; i <= size; i++) {
				tmp = current[i - 1] + current[i + 1];
				if (tmp < 3 || tmp>7) { //합이 3보다 적거나 7보다 많으면 한마리가 죽음
					next[i] = (current[i] > 0 ? current[i] - 1 : current[i]);
				}
				else if (tmp == 3) {	//3일때는 유지
					next[i] = current[i];
				}
				else {					//셀에 살아있는 박테리아 수의 합이 4, 5, 6, 7이면 한마리 추가
					//9는 넘으면 안됨
					next[i] = (current[i] < 9 ? current[i] + 1 : current[i]);
				}
			}
			int* ptr = current;
			current = next;
			next = ptr;
		}

		for (int i = 1; i <= size; i++) {
			cout << current[i] << " ";
		}
		cout << endl;

		delete[] current;
		delete[] next;

	}
}