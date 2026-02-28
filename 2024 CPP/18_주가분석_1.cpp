#include <iostream>
using namespace std;
void stock() {
	int pre = -1;
	int cur = -1;
	int next = 0;


	int size = 0;
	int i = 0;

	int count = 0;
	int num = 0;

	cin >> size;

	for (i = 0; i < size; i++) {
		cin >> num;
		if (pre == -1) {
			pre = num;
			continue;
		}
		if (cur == -1) {
			cur = num;
			continue;
		}
		next = num;
		if (cur == next) {
			continue;
		}
		else if (pre<cur && cur>next) {
			count++;
		}
		pre = cur;
		cur = next;
	}

	cout << count << endl;

}
int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		stock();
	}
	return 0;
}