#include <iostream>
using namespace std;
void tri_print() {
	int k = 0;
	int i = 0;
	int j = 0;
	int add = 0;
	cin >> k;
	for (i = 1; i <= k; i++) {
		for (j = 0; j < i; j++) {
			cout << i * (j + 1) << " ";
		}
		cout << "\n";
	}


}
int main() {
	int t = 0;
	int i = 0;
	cin >> t;
	for (i = 0; i < t; i++) {
		tri_print();
	}

}