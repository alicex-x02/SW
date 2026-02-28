#include <iostream>
#include <vector>
using namespace std;
void sub_array_sum() {
	int num = 0;
	int sum = 0;
	int i = 0; 
	int j = 0;
	int least_length = 0;
	cin >> num >> sum;

	vector<int>array(num);
	for (i=0; i < num; i++) {
		for (j = 0; j < i; j++) {
		
		}
	}

	cout << least_length << endl;
}
int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		sub_array_sum();
	}
	return 0;
}