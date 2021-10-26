# map과 lambda

# 일반 함수 이용
def func_mul(x):
    return x * 2

result1 = list(map(func_mul, [5, 4, 3, 2, 1]))
print(f"map(일반함수, 리스트) : {result1}")

# 람다 함수 이용
result2 = list(map(lambda x: x * 2, [5, 4, 3, 2, 1]))
print(f"map(람다함수, 리스트) : {result2}")
# 람다 함수의 이용!@
# lambda x : x * 2 에서
# x는 인자 x * 2는 반환값으로 추측가능한 부분을 생략함.
# map의 인자로 사용할 함수가 일회성이거나 매우 짧은 경우에는 람다 함수를 사용해서 넘기는 게 좀 더 효율적!

