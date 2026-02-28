#include <iostream>
#include <string>

using namespace std;

void func(int* arr, int pos) {
	int tmp = arr[pos + 1];

	while (pos >= 0) {
		if (arr[pos] > tmp) {
			arr[pos] -= tmp;
			return;
		}
		else {
			if (pos == 0) {
				arr[pos] = arr[pos] - tmp + 10;
				break;
			}
			arr[pos--] = arr[pos] - tmp + 10;
			tmp = 1;
		}
	}
}
int main() {
	int tc;

	cin >> tc;


	while (tc--) {
		string str;
		//cin >> str;
		str = "964197531";
		int* arr = new int[str.length()] {0, };

		if (str.length() < 2) {
			cout << 0 << endl;
			continue;
		}

		//아스키 감안해야함
		//아홉자리수면 여덟자리로 감안 
		for (int i = 0; i < str.length(); i++) {
			arr[i] = str[i] - 48;
			cout << arr[i];
		}
		cout << endl;


		for (int i = str.length() - 2; i >= 0; i--) {
			func(arr, i);
		}


		for (int i = 1; i < str.length(); i++) {
			cout << arr[i];
		}
		cout << endl;




		delete[]arr;

	}
	return 0;

}