#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//상하좌우 방향 정의
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

//방 크기를 계산하는 함수
//수정해야되서 참조 변수~~
int room_size_calculator(vector<string>& grid, int x, int y, int n, int m) {
    int room_size = 0;

    //pair...사용해주기... 값을 쌍으로 저장 -> 두칸짜리 벡터 
    //방문해야 할 위치를 저장할 스택하나 만들기
    vector<pair<int, int>> stack; 
    stack.push_back({ x, y });

    //지나간 곳을 '#'으로 방문 처리
    grid[x][y] = '#'; 

    while (!stack.empty()) {
        //스택에서 위치를 꺼냄

        pair<int, int> current = stack.back();
        stack.pop_back();
        
        //현재 탐색 중인 x와 y의 좌표
        int cx = current.first;
        int cy = current.second;

        //방 크기 증가
        room_size++; 

        //상하좌우 탐색 상하좌우 4방향이라 4개
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            //유효한 위치인지 확인
            //이동한 x와 y좌표가 평면 범위를 벗어나지 않는가
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                grid[nx][ny] = '#'; // 방문 처리
                stack.push_back({ nx, ny }); // 다음 방문 위치 추가
            }
        }
    }

    return room_size;
}

void solve() {
    int m, n;
    cin >> m >> n;

    //평면도를 줄별로 입력받기
    vector<string> line(n);
    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }

    vector<int> room_sizes; //각 방의 크기를 저장할 벡터

    //전체 공간을 돌면서 방 크기 계산
    //2차원 공간이니까 반복문 2개
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (line[i][j] == '.') { //빈 공간이면 방 탐색 시작 '.'이 빈공간 '+'이 닫힌공간
                int size = room_size_calculator(line, i, j, n, m);
                //벡터 뒤에다 하나 추가하는거 -> 크기를 재할당해서 안좋은 함수
                room_sizes.push_back(size);
            }
        }
    }

    /*
    방 크기를 내림차순으로 정렬해주기... 그냥 소트 함수를 쓰자.

    검색해봄..
    rbegin(): 컨테이너의 마지막 요소를 가리키는 역방향 반복자를 반환
    rend(): 컨테이너의 첫 번째 요소의 앞을 가리키는 역방향 반복자를 반환
    두개를 사용하면 컨테이너의 마지막 요소 -> 첫 요소까지 접근 가능
    */
    sort(room_sizes.rbegin(), room_sizes.rend());

    // 결과 출력
    cout << room_sizes.size() << endl; // 방 개수
    for (int size : room_sizes) {
        cout << size << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
