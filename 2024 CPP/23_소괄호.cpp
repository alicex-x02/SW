#include <iostream>
#include <stack>					//스택 사용
#include <string>					//string 사용해서 문자열로 받자
using namespace std;

void parenthesis() {
	stack<char> STACK;				//스택 선언
	string input;
	getline(cin, input);			//공백이 포함됨 문자열

	for (char ch : input) {
		if (ch == '(') {			//여는 괄호
			STACK.push(ch);
		}
		else if(ch == ')') {						//닫는 괄호
			if (STACK.empty()) {	//스택이 비어 있으면 바로 끊음
				cout << 0 << endl;
				return;
			}
			STACK.pop();			//아니면 pop
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
	cin.ignore();				//자꾸 t입력하면 자동으로 1이 나와서 찾아봄. 
								//t입력받고 getline 호출할때 남은 계행을 읽어서 무시해주는 함수 사용해야한다고함 -> 검색함
	while (t--) {
		parenthesis();
	}
	return 0;
}