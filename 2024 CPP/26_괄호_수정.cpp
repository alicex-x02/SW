#include <iostream>
#include <stack>					
#include <string>					
using namespace std;

void parenthesis() {
	stack<char> STACK;				

	string input;
	getline(cin, input);			

	for (char ch : input) {
		if (ch == '(' || ch == '[' || ch == '{') {
			STACK.push(ch);
		}
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (STACK.empty()) {	
				cout << 0 << endl;
				return;
			}
			char top = STACK.top();
			if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
				cout << 0 << endl;
				return;
			}
			STACK.pop();
		}
	
	}
		
	if (STACK.empty()) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}
int main() {
	int t = 0;
	cin >> t;
	cin.ignore();				
	while (t--) {
		parenthesis();
	}
	return 0;
}