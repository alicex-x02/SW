"""
2025-2 선형대수 G조
정유진, 문다인, 아크바이 아미라, 유환희, 홍진선
선형 연립방정식 해 구하기
1. 해가 없음
2. 유일한 해 (LU분해)
3. 무수히 많은 해 (자유변수 이용하여 표현)
"""

#가우스 소거 + 해 판별 함수 
#행 연산 -> 계단행렬(row echelon form)
#pivot 개수 = rank(A)
#rank < n(변수 개수) -> 자유변수 존재 -> 해는 무한히 많다.
#rank = n -> 모든 변수가 pivot으로 결정 -> 유일해가 존재한다.
def gaussian_elimination(A):
    #첨가 행렬 A를 복사
    M = [row[:] for row in A]
    #방정식의 개수
    m = len(M)
    #변수의 개수 / 상수항 빼서 -1 해줌
    n = len(M[0]) - 1

    #현재 row
    row = 0

    #pivot column 저장 리스트
    pivot_cols = []

    #0 ~ n-1번째 column까지 순회하며 pivot을 찾아줌
    for col in range(n):
        #현재 column에서 pivot으로 쓸 row index
        pivot = None
        #남은 row에서 pivot 후보
        for r in range(row, m):
            if abs(M[r][col]) > 1e-12:
                pivot = r
                break
        #pivot이 없다 -> column 통째로 스킵
        if pivot is None:
            continue

        #pivot이 현재 row가 아니다 -> row 교환
        if pivot != row:
            M[row], M[pivot] = M[pivot], M[row]

        #pivot값 가져오기
        pivot_val = M[row][col]

        #pivot이 있는 column 전체를 pivot 값으로 나누기 -> pivot 1 만들기
        M[row] = [v / pivot_val for v in M[row]]

        #pivot 아래 row에서 column 0 만들어주기
        for r in range(row+1, m):
            #없애고 싶은거
            factor = M[r][col]
            #거의 0이면 계산 x
            if abs(factor) > 1e-12:
                #r row = r row - factor x pivot row
                M[r] = [M[r][c] - factor * M[row][c] for c in range(n+1)]

        #현재 column -> pivot column
        pivot_cols.append(col)
        #다음 pivot -> 다음 row 에서 찾기 +1
        row += 1
        #row 끝나면 끝
        if row == m:
            break
    #행렬, pivot colume 반환
    return M, pivot_cols

#LU 분해
#A = LU 형태
#L : 하삼각행렬(lower triangular), 대각성분 1
#U : 상삼각행렬(upper triangular)
#조건 :
#1) A -> 정사각행렬
#2) pivot이 0 X 
#LU 분해가 가능한 경우 
#1) Ly = b
#2) Ux = y
def lu_decomposition(A):
    #행렬 크기
    n = len(A)
    #상삼각행렬 U -> A를 복사한거에서 시작
    U = [row[:] for row in A]
    #하삼각행렬 L -> 0으로 추기화
    L = [[0]*n for _ in range(n)]
    #row 교환 정보를 기록하는 pivot
    piv = list(range(n))

    #i번째 열에 대한 pivot -> 소거 
    for i in range(n):
        #절댓값이 가장 큰 원소 가진 행 pivot
        pivot = max(range(i, n), key=lambda r: abs(U[r][i]))
        #0이면 불가 -> 예외 처리
        if abs(U[pivot][i]) < 1e-12:
            raise ValueError("LU 분해 불가(0 pivot)")

        #pivot row가 현재 row i랑 다르면 row 교환 해줌
        if pivot != i:
            U[i], U[pivot] = U[pivot], U[i]
            piv[i], piv[pivot] = piv[pivot], piv[i]

        #L의 대각 원소 -> 1 
        L[i][i] = 1

        #i 아래 행에 대해서 L과 U를 계속 갱신
        for r in range(i+1, n):
            # L[r][i] = U[r][i] / U[i][i]
            L[r][i] = U[r][i] / U[i][i]
            # U[r][*] = U[r][*] - L[r][i] * U[i][*]
            for c in range(i, n):
                U[r][c] -= L[r][i] * U[i][c]
    #L, U, pivot 반환
    return L, U, piv

#LU 분해 한거 -> Ax = b
def lu_solve(L, U, piv, b):
    #행렬 크기
    n = len(L)
    #pivot 정보보고 b 순서를 재배치 해줌 -> 아까 행 교환 한거
    bp = [b[p] for p in piv]

    #Ly = bp
    y = [0]*n
    for i in range(n):
        # y[i] = bp[i] - Σ L[i][j] * y[j] (j < i)
        y[i] = bp[i] - sum(L[i][j]*y[j] for j in range(i))

    #Ux = y
    x = [0]*n
    for i in reversed(range(n)):
        #대각 원소 0 -> 역행렬 x
        if abs(U[i][i]) < 1e-12:
            raise ValueError("해 계산 중 0 pivot 발생")
        #x[i] = (y[i] - SUM U[i][j] * x[j]) / U[i][i]  (j > i)
        x[i] = (y[i] - sum(U[i][j]*x[j] for j in range(i+1, n))) / U[i][i]
    #x 반환
    return x

#출력용 
def format(val):
    # 거의 정수라면 정수로 출력
    if abs(val - round(val)) < 1e-12:
        return str(int(round(val)))
    # 소수는 소수점 둘째 자리까지 반올림
    return f"{val:.2f}"

def infinite_solution_expression(R, pivot_cols):
    #행 개수
    m = len(R)
    #변수 개수 / 상수 빼서 -1
    n = len(R[0]) - 1
    #pivot 아닌 column = 자유 변수 -> colume index
    free_vars = [c for c in range(n) if c not in pivot_cols]

    #변수 표현식을 문자열로 저장할 거임
    expr = ["0"] * n

    #자유변수로 사용할 알파벳들 / x, y, z는 미지수로 많이 써서 패스 
    names = ["s", "t", "u", "v", "w", "q"]
    #각 자유변수 column에 이름을 줌
    for i, fv in enumerate(free_vars):
        expr[fv] = names[i]

    #거꾸로 pivot 변수 결정
    for r in reversed(range(m)):
        #현재 row에서 pivot 있는 column 찾기
        pivot_col = None
        for c in range(n):
            if abs(R[r][c]) > 1e-12:
                pivot_col = c
                break
        #pivot x -> 패쓰
        if pivot_col is None:
            continue
        #pivot column이 자유변수인 경우 -> 패쓰
        if pivot_col in free_vars:
            continue
        
        #상수항 값
        sangsuhang = R[r][-1]
        #복사
        s = sangsuhang

        #자유변수 + 정해진 변수 관련 항 모을거임
        parts = []
        #pivot column 오른쪽에 있는 column 순회
        for c in range(pivot_col+1, n):
            #coefficient
            coeff = R[r][c]
            #0이면 패쓰
            if abs(coeff) < 1e-12:
                continue
            
            #해당 변수 -> 표현식
            term = expr[c]
            #term안에 알파벳이 있다 -> 자유변수 포함된 표현식
            if any(ch.isalpha() for ch in term):
                #coefficient가 음수일 때와 양수일 때 부호를 다르게 처리
                if coeff < 0:
                    #음수인 경우 절대값 1이라면 생략하고 변수만 붙임
                    parts.append(f"+ {format(abs(coeff))}*{term}" if abs(coeff) != 1 else f"+ {term}")
                else:
                    #양수 계수 -좌변이동
                    parts.append(f"- {format(coeff)}*{term}" if coeff != 1 else f"- {term}")
            else:
                #알파벳 없으면 상수항 취급
                s -= coeff * float(term)
        #상수항 + 자유변수항
        final = format(s)
        for p in parts:
            final += " " + p
        #pivot column에 해당하는 변수 표현식
        expr[pivot_col] = final

    #합칠 문자열
    out = []
    for i in range(n):
        out.append(f"x{i+1} = {expr[i]}")
    return "\n".join(out)

#메인 문제 풀이 함수
def solve_system(A):
    #가우스 조던 소거 -> R, pivot column 획득
    R, pivot_cols = gaussian_elimination(A)
    #row 개수
    m = len(A)
    #변수 개수
    n = len(A[0]) - 1

    #해 없는지 확인
    for r in range(m):
        if all(abs(R[r][c]) < 1e-12 for c in range(n)) and abs(R[r][-1]) > 1e-12:
            return ("no_solution", None)
    #랭크 -> pivot column 개수
    rank = len(pivot_cols)

    #CASE 1) rank < n -> 자유변수 -> 무한해
    #자유변수가 있다 = 해 공간의 차원이 1 이상
    if rank < n:
        return ("infinite", (R, pivot_cols))

    #CASE 2) rank = n
    #유일해이긴 하나 LU는 정사각일 때만 가능
    if rank == n:
        #정사각 x ->  LU 분해 x
        if m != n:   
            return ("lu_fail", None)

        #정사각 ->  LU 분해
        M = [row[:] for row in A]
        #계수 행렬
        A_mat = [row[:n] for row in M]
        #상수항 
        b = [row[-1] for row in M]

        try:
            #계수 행렬을 LU 분해 
            L, U, piv = lu_decomposition(A_mat)
            #LU 분해 결과로 해 계산
            x = lu_solve(L, U, piv, b)
        except Exception:
            #에러나면 실패로 간주
            return ("lu_fail", None)
        #성공 + 유일한 해 인 경우 결과를 반환
        return ("unique", (L, U, x))

    #진짜 만약 만약에 아무것도 안걸리면.... unknown 처리 
    return ("unknown", None)


#메인 함수 
def main():
    #방정식 개수, 변수 개수 입력
    print("방정식 개수 m, 변수 개수 n 입력 (예: 2 3):")
    m, n = map(int, input().split())

    #첨가 행렬 입력
    print(f"첨가행렬 입력 (각 행 {n+1}개):")
    #A에 저장
    A = []
    #m row 입력
    for _ in range(m):
        row = list(map(float, input().split()))
        if len(row) != n+1:
            print("열 개수가 맞지 않습니다.")
            return
        A.append(row)
    #해의 종류 (해 없다, 있다, 무한하다...), data 받아옴
    kind, data = solve_system(A)

    print("\n<<결과 출력>>")

    #해가 없음
    if kind == "no_solution":
        print("해가 없음")

    #유일한 해
    elif kind == "unique":
        L, U, x = data
        print("\n유일한 해")
        print("\n[L 행렬]")
        for r in L:
            print(" ".join(format(v) for v in r))

        print("\n[U 행렬]")
        for r in U:
            print(" ".join(format(v) for v in r))

        print("\n[해]")
        for i, val in enumerate(x):
            print(f"x{i+1} = {format(val)}")
    #무한히 많은 해
    elif kind == "infinite":
        R, pivot_cols = data
        print("무수히 많은 해 (자유변수 존재):\n")
        print(infinite_solution_expression(R, pivot_cols))

    #이런 테스트 케이스는 없을거라고 하지만 혹시나 해서 만들어둠
    elif kind == "lu_fail":
        print("유일한 해는 존재하지만 LU 분해를 수행할 수 없습니다.")


if __name__ == "__main__":
    main()
