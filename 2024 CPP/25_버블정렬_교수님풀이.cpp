#include <iostream>

using namespace std;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int tc, size;

	cin >> tc;

	while (tc--) {
		cin >> size;
		int* arr = new int [size];

		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < size - 1; i++) {
		
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
				}
			}
			for (int j = 0; j < size; j++) {
				cout << arr[i] << ' ';
			}
			cout << endl;
		}

		delete[]arr;

	
	}


}