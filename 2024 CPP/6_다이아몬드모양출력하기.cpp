#include <iostream>
using namespace std;

int main() {
    int T = 0;
    int a = 0;
    cin >> T;
    for (a = 0; a < T; a++) {
        int N, i, j, k = 0;
        cin >> N;
        for (i = 1; i <= (N / 2) + 1; i++) {
            for (j = (N - 1) / 2; j >= i; j--) {
                cout << "*";
            }
            for (j = 1; j <= (i * 2) - 1; j++) {
                cout << "+";
            }
            for (j = (N - 1) / 2; j >= i; j--) {
                cout << "*";
            }
            cout << endl;
        }
        for (i = 1; i <= (N / 2); i++) {
            for (j = 2; j <= i + 1; j++) {
                cout << "*";
            }
            for (j = N - 2 - i; j >= i - 1; j--) {
                cout << "+";
            }
            for (j = 2; j <= i + 1; j++) {
                cout << "*";
            }
            cout << endl;
        }



    }
    return 0;
}