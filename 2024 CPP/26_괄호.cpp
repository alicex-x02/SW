#include <iostream>
#include <stack>					//스택 사용
#include <string>					//string 사용해서 문자열로 받자
using namespace std;

void parenthesis() {
	stack<char> STACK_1;				//스택 선언()
	stack<char> STACK_2;				//스택 선언 {}
	stack<char> STACK_3;				//스택 선언 []
	string input;
	getline(cin, input);			//공백이 포함됨 문자열

	for (char ch : input) {
		switch (ch) {
			case '(':
				STACK_1.push(ch);
				break;
			case '[':
				STACK_2.push(ch);
				break;
			case '{':
				STACK_3.push(ch);
				break;
			case ')':
				if (STACK_1.empty())  {	//스택이 비어 있으면 바로 끊음
					cout << 0 << endl;
					return;
				}
				STACK_1.pop(); 			//아니면 pop
				break;
			case ']':
				if (STACK_2.empty())  {	//스택이 비어 있으면 바로 끊음
					cout << 0 << endl;
					return;
				}
				STACK_2.pop();			//아니면 pop
				break;
			case '}':
				if (STACK_3.empty()) {	//스택이 비어 있으면 바로 끊음
					cout << 0 << endl;
					return;
				}
				STACK_3.pop();			//아니면 pop
				break;
		}
	}
	if (STACK_1.empty()&& STACK_2.empty() && STACK_3.empty()) {
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