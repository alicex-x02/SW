#include <iostream>
#include <string>

using namespace std;

//dfs 구현

int directions[][2] = { {1,0}, {-1, 0}, {0, 1}, {0, -1} };

int check_room_size(string *room, int row, int col, int r_pos, int c_pos, int size) {
	
	size++;
	room[r_pos][c_pos] = '+';

	for (int i = 0; i < 4; i++) {
		int r_tmp = r_pos + directions[i][0];
		int c_tmp = c_pos + directions[i][1];

		if ((r_tmp >= 0 and r_tmp < row) and (c_tmp >= 0 and c_tmp < col) and (room[r_tmp][c_tmp] == '.')) {
			size = check_room_size(room, row, col, r_tmp, c_tmp, size);
		}
	}
	return size;
}

int main() {
	int t;
	int row, col;
	cin >> t;

	while (t--) {
		int room_size[100] = { 0 };
		int total_cnt = 0;
		cin >> col >> row;
		string* room = new string[row];
		for (int i = 0; i < row; i++) {
			cin >> room[i];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (room[i][j] == '.') {
					room_size[total_cnt++] = check_room_size(room, row, col, i, j, 0);
				}
			}
		}

		//정렬 넣으면 됨

		cout << total_cnt << endl;
		for (int i = 0; i < total_cnt; i++) {
			cout << room_size[i] << ' ';
		}
		cout << endl;

		delete[] room;

	}

	return 0;
}