"""
2025-2 선형대수 G조
정유진, 문다인, 아크바이 아미라, 유환희, 홍진선
행렬의 멱승
"""
#실행 시간 측정을 위한 모듈
#각각 방법 따라 걸린 시간을 측정하여 실제로 효과적인지 비교해 볼 수 있다. 
import time

#입력 함수
def read_inputs():
    #행렬 크기 입력
    n = int(input("행렬 크기 n (정방행렬 n x n): ").strip())
    print(f"{n}x{n} 행렬 A의 원소를 행 단위로 입력하세요. (공백으로 구분)")
    
    #행렬 A 입력
    A = []
    for i in range(n):
        row = input(f"{i+1}번째 행: ").strip().split()
        if len(row) != n:
            raise ValueError(f"{i+1}번째 행에 원소 {n}개를 입력해야 합니다.")
        A.append([float(x) for x in row])

    #멱승 지수 입력
    m = int(input("몇 승(m): ").strip())
    if m < 0:
        raise ValueError("이 프로그램은 m >= 0만 지원합니다.")
    return A, m


#기본 행렬 연산
def identity(n):
    #n x n 단위행렬 생성
    return [[1.0 if i == j else 0.0 for j in range(n)] for i in range(n)]


def mat_mul(A, B):
    #행렬 A와 B의 곱 계산
    n = len(A)
    m = len(B[0])
    p = len(B)
    result = [[0.0 for _ in range(m)] for _ in range(n)]

    for i in range(n):
        for k in range(p):
            aik = A[i][k]
            #곱셈 최소화를 위한 최적화
            if aik == 0:
                continue
            for j in range(m):
                result[i][j] += aik * B[k][j]
    return result


#1) 기존 방식 (반복 행렬곱)
def matrix_power_naive(A, m):
    #A^0은 단위행렬
    n = len(A)
    if m == 0:
        return identity(n)

    #A를 m-1번 반복 곱함
    result = [row[:] for row in A]
    for _ in range(m - 1):
        result = mat_mul(result, A)
    return result


#2) Binary Exponentiation (분할정복)
def matrix_power_bi_ex(A, m):
    #결과를 단위행렬로 초기화
    n = len(A)
    result = identity(n)
    base = [row[:] for row in A]

    #이진 거듭제곱 알고리즘
    while m > 0:
        #m이 홀수이면 결과에 현재 행렬을 곱함
        if m & 1:              
            result = mat_mul(result, base)
        #행렬 제곱
        base = mat_mul(base, base)
        #지수를 2로 나눔
        m >>= 1
    return result


#출력 함수
def print_matrix_int(M):
    #결과 행렬을 정수 형태로 출력
    for row in M:
        print(" ".join(str(int(round(x))) for x in row))

# 메인 함수
def main():
    #입력 받기
    A, m = read_inputs()

    print("\n================ 결과 ================")
    print(f"m = {m}")

    #기존 방식 실행 및 시간 측정
    t0 = time.perf_counter()
    naive = matrix_power_naive(A, m)
    t1 = time.perf_counter()

    print("\n[1) 기존 방식(반복 행렬곱)]")
    print_matrix_int(naive)
    print(f"걸린 시간: {t1 - t0:.6f} sec")

    #Binary Exponentiation 실행 및 시간 측정
    t2 = time.perf_counter()
    fast = matrix_power_bi_ex(A, m)
    t3 = time.perf_counter()

    print("\n[2) Binary Exponentiation(분할정복)]")
    print_matrix_int(fast)
    print(f"걸린 시간: {t3 - t2:.6f} sec")

    print("=====================================\n")


#프로그램 시작점
if __name__ == "__main__":
    main()