import random

arr = list()
print(arr)

for i in range(10):
    arr.append(random.randint(1, 100))

print("*" * 40)
print(arr)
print("*" * 40)

# 이 리스트 안에서 가장 큰 값을 출력하시오
arr.sort()
print(arr[-1])

# 2번째 값도 출력하깅
print(arr[1])

li = []

# 가수 세 명을 입력 받기
for i in range(0, 3, 1):
    li.append(input('가수 이름을 쓰세요 : '))

print('-' * 20)
print(li)
print(f'리스트 개수 {len(li)}개 입니다.')