arr = [1, 10.2, 100.3, 2.3, 20.2, 200.3, 3, 30, 300]

result1 = list(filter(lambda n : n < 10, arr))
result2 = list(filter(lambda n : isinstance(n, int), arr))
result3 = list(filter(lambda n : isinstance(n, float), arr))

print(f'원래 리스트 : {arr}')
print(f'10보다 작은 수 : {result1}')
# filter를 통해 10보다 작은 수만..
print(f'정수만 출력 {result2}')
# isinstance는 특정 자료형이 맞는지 검사!
# 따라서 int인거 출력
print(f'실수만 출력 {result3}')
# 그렇다면 이것은 float형만 출력한다!