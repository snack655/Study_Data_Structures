# 리스트에 값을 하나씩 더해서 새로운 리스트를 만드는 작업
myList = [1, 2, 3, 4, 5]

# for 반복문 이용
result1 = []
for val in myList:
    result1.append(val + 1)

# 배열 하나씩 돌면서 1씩 더해준다.

print(f'result1 : {result1}')


# map 함수 이용
def add_one(n):
    return n + 1


result2 = list(map(add_one, myList))  # map반환을 list로 변환
print(f'result2 : {result2}')
# add_one(myList[0]) -> 2
# add_one(myList[1]) -> 3
# ...
