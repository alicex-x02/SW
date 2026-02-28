#define _CRT_SECURE_NO_WARNINGS
#include "cstring"
#include "MyISBN.h"
#include <cctype>

// constructors
MyISBN::MyISBN()
{
	//초기화
	isbn[0] = '\0';
}
MyISBN::MyISBN(char isbn_number[])
{
	//복사해줌
	strcpy(isbn, isbn_number);
}
// utility functions
bool MyISBN::isCorrectNumber() const
{
	//문법 맞고, 체크섬 맞으면 true
	if (isSyntaxValid() && isCheckSumValid())
		return true;
	else
		return false;
}
// private functions
bool MyISBN::isSyntaxValid() const
{

	int length = strlen(isbn);

	//'-'로 시작하면 거짓
	if (isbn[0] == '-') {
		return false;
	}

	//'-'이랑 부분별로 숫자 몇개인지 세야함
	int hyphen_count = 0;
	int section[4] = { 0 }; //세션별로 길이 저장
	//1. 첫번째 세션 최대 5자리
	//2. 두번째 세션 최대 7자리
	//3. 세번째 세션 최대 6자리
	//4. '-'은 최대 3개까지 가능
	//5. 세션이 비어 있으면 안됨 '-' '-' 연속 이런거 안됨

	int section_index = 0;

	for (int i = 0; i < length; i++) {
		if (isbn[i] == '-') {
			hyphen_count++;
			if (section_index >= 3 || section[section_index] == 0) { //4, 5번
				return false;
			}
			section_index++; //'-' 나왔으니까 다음 섹션으로 넘기기
		}
		//isdigit 써서 지금 만난게 숫자가 맞는지 체크
		//아니면 마지막 자리 (체크섬)이 X인지 확인 
		else if (isdigit(isbn[i]) || (i == length - 1 && isbn[i] == 'X')) {
			//만난게 숫자가 맞다면 세션에 ++해서 세션의 길이를 추가시켜주기
			section[section_index]++;
		}
		else {
			//그외는 return
			return false;
		}
	}

	if (hyphen_count != 3) {
		//4. '-'은 최대 3개까지 가능
		return false; 
	}
	if (section[0] < 1 || section[0] > 5 || //1. 첫번째 세션 최대 5자리 -> 4까지
		section[1] < 1 || section[1] > 7 || //2. 두번째 세션 최대 7자리 -> 6까지
		section[2] < 1 || section[2] > 6 || //3. 세번째 세션 최대 6자리 -> 5까지
		section[3] != 1) {                  // 체크섬 -> 무조건 한자리
		return false; // 섹션 길이가 조건에 맞지 않음
	}

	return true;
}
bool MyISBN::isCheckSumValid() const
{
	//isbn의 길이 13 나오려나
	int length = strlen(isbn);

	//다 더한거
	int sum = 0;

	//하나씩 늘려가는거
	int digit_count = 0;

	//체크섬 계산
	//첫번째 숫자 -> 아홉번째 숫자 -> 각각 차례로 10부터 2까지 곱해서 더한것 + 체크썸 숫자 = 11의 배수
	for (int i = 0; i < length; i++) {
		//'-'은 무시하고 continue
		if (isbn[i] == '-') {
			continue; 
		}

		//마지막 자리가 'X'인 경우 10으로 처리
		if (isbn[i] == 'X' && digit_count == 9) {
			sum += 10; 
		}
		//숫자일때 아스키 해주고 각각 차례로 10부터 2까지 곱해서 더해준것
		//digit count를 하나씩 늘려서 10, 9, 8....이런식으로 돌아가게 해줌
		else if (isdigit(isbn[i])) {
			sum += (isbn[i] - '0') * (10 - digit_count);
		}
		//숫자나 '-' 아닐때
		else {
			return false; 
		}

		digit_count++;
	}

	//다 더한값이 11의 배수여야함
	return sum % 11 == 0;
}