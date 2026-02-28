#include <iostream>
#include <vector>
using namespace std;

void bubble_sort() {
	int size = 0;
	int i = 0;
	int j = 0;
	int temp = 0;
	cin >> size;
	vector<int> bubble(size);
	for (i = 0; i < size; i++) {
		cin >> bubble[i];
	}
	for (i = 0; i < size-1; i++) {
		for (j = 0; j < size-i-1; j++) {
			if (bubble[j] > bubble[j+1]) {
				temp = bubble[j];
				bubble[j] = bubble[j+1];
				bubble[j+1] = temp;
			}
			
		}
		for (j = 0; j < size; j++) {
			cout << bubble[j] << " ";
		}
		cout << endl;
	}
	

}


int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		bubble_sort();
	}
	return 0;
}