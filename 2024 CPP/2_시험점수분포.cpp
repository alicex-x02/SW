#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

int main() {
	int T = 0;
	int i, j, k = 0;
	cin >> T;
	for (i = 0; i < T; i++) {
		int N = 0; //number of students
		cin >> N;
		map<int, int> stu_score; //map으로 점수와 학생수 저장
		for (j = 0; j < N; j++) {
			int score = 0;
			cin >> score;
			stu_score[score]++;
		}

		for (const auto& print_score : stu_score) {
			cout << print_score.first << " " << print_score.second << " ";
		}
		cout << "\n";

	}
	return 0;
}