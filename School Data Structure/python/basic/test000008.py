# 제어문 : if문

a = 5
if a >= 3:
    print('3이상')
elif a > 1:
    print('3미만 1초과')
else:
    print('1이하')

# 더 큰 수 출력하기

b, c = map(int, input().split())
if b > c:
    print(b)
elif c > b:
    print(c)
else:
    print("같다")

# 숫자 하나를 입력받아 기준 점수에 따른 등급을 출력
num = int(input())
if num >= 70:
    print("최우수")
elif num >= 50:
    print("우수")
elif num >= 20:
    print("보통")
else:
    print("노력 필요")