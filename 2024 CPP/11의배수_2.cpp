#include <iostream>
#include <string>

using namespace std;

void parse(string str, int arr[]) { // 문자열을 정수 100개로 나누는 함수
    int idx = 99;
    for (int i = str.length() - 1; i > -1; i--) {
        arr[idx--] = str[i] - '0';
    }
}

int lsb(int arr[]) { // 마지막 자리수를 떼어내는 함수 (shift)
    int r = arr[99]; // 마지막 자리수

    for (int i = 99; i > 0; i--) { // 마지막 자리부터 앞자리의 수를 당겨오기
        arr[i] = arr[i - 1];
    }

    arr[0] = 0; // 맨 앞자리를 무조건 0으로 만든다
    return r;
}

void sub(int arr[], int s) { // 뺄셈 함수
    arr[99] -= s; // 마지막 자리수 - 자연수 시도

    for (int i = 99; i > 0; i--) { // 받아내림하는 반복문
        if (arr[i] >= 0) break; // (마지막 자리수 - 자연수)가 양수라면 받아내림할 필요가 없음

        // (마지막 자리수 - 자연수)가 음수라면
        arr[i - 1]--; // 앞자리에서 받아내림
        arr[i] += 10;
    }
}

bool cmp_ten(int arr[]) { // 배열에 저장된 수가 10보다 큰지 판별하는 함수
    for (int i = 98; i > -1; i--) { // 두번째 자리부터
        if (arr[i]) return true; // 0이 아닌 값이 있다면 10보다 큰 수
    }

    return false; // 0이 아닌 값이 없다면 두번째 자리부터 모두 0이므로 10보다 작은 수
}

int main() {
    int t; // 테스트케이스 개수

    cin >> t;

    while (t--) {
        int sub_str[100]{ 0, }; // 100자리 정수 배열
        string test, quo;

        cin >> test; // 문자열 숫자 입력

        parse(test, sub_str); // 문자열을 100자리 정수 배열로 변환

        while (cmp_ten(sub_str)) { // 두번째 자리가 0이 아닐 동안 => 한자리 수가 될때까지
            int r = lsb(sub_str);
            sub(sub_str, r);

            quo = (char)(r + '0') + quo; // 떼어낸 마지막 자리수를 문자로 바꿔 결과의 앞에 저장
        }

        if (sub_str[99]) cout << 0 << endl; // 마지막 자리수가 0이 아니라면 11의 배수가 아님
        else cout << quo << endl; // 마지막 자리수가 0이면 11의 배수이므로 몫 출력
    }
}