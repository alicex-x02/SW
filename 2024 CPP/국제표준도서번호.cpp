#include <iostream>
#include "MyISBN.h"

using namespace std;

int main() {
	int t = 0;
	cin >> t;
	
	while (t--) {
		char isbn[max_length + 1];
		cin >> isbn;

		MyISBN bookNumber(isbn);
		if (bookNumber.isCorrectNumber())
			cout << "1" << endl;
		else
			cout << "0" << endl;
	
	}


	return 0;
}