#include <iostream>

using namespace std;

int main() {
	int tc, n, s = 0;
	cin >> tc;

	while (tc--) {
		int total = 0;
		int left = 0;
		int right = 0;
		int result = 99999999;
		cin >> n >> s;

		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				total += arr[i];
				if (total >= s) {
					if (total == s) {
						result = j - i + 1 < result ? j - i + 1 : result;
						break;
					}
					
				}
			}
		}
		*/

		while (left <= right && right < n) {
			if (total < s) {
				total += arr[right];
				right++;
			}
			else {
				if (total == s) {
					result = right - left < result ? right - left : result;
				}
				total -= arr[left];
				left++;
			}
		}
		cout << result << endl;
	}
	return 0;
}